#include "content.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

Content::Content(int content_id, const QString &title, const QString &type,
                 const QString &category, const QString &author,
                 int release_year, bool limited_offer, int view_count)
    : content_id(content_id), title(title), type(type),
    category(category), author(author),
    release_year(release_year), limited_offer(limited_offer), view_count(view_count) {}

int Content::getContentId() const { return content_id; }
QString Content::getTitle() const { return title; }
QString Content::getType() const { return type; }
QString Content::getCategory() const { return category; }
QString Content::getAuthor() const { return author; }
int Content::getReleaseYear() const { return release_year; }
int Content::getViewCount()  const { return view_count; }
bool Content::isLimitedOffer() const { return limited_offer; }

void Content::setContentId(int id) { content_id = id; }
void Content::setTitle(const QString &newTitle) { title = newTitle; }
void Content::setType(const QString &newType) { type = newType; }
void Content::setCategory(const QString &newCategory) { category = newCategory; }
void Content::setAuthor(const QString &newAuthor) { author = newAuthor; }
void Content::setReleaseYear(int year) { release_year = year; }
void Content::setLimitedOffer(bool offer) { limited_offer = offer; }

void Content::updateContent(){
    QSqlQuery query;
    query.prepare("UPDATE Content SET title = :title, type = :type, category = :category, "
                  "author = :author, release_year = :release_year, limited_offer = :limited_offer "
                  "WHERE title = :title");

    query.bindValue(":title", title);
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":author", author);
    query.bindValue(":release_year", release_year);
    query.bindValue(":limited_offer", limited_offer);
    query.bindValue(":content_id", content_id);

    if (!query.exec()) {
        qDebug() << "Błąd podczas zapisywania danych: " << query.lastError().text();
    } else {
        qDebug() << "Dane zostały zapisane pomyślnie!";
    }
}

void Content::addContent() {
    QSqlQuery query;
    query.prepare("INSERT INTO Content (title, type, category, author, release_year, limited_offer) "
                  "VALUES (:title, :type, :category, :author, :release_year, :limited_offer)");

    query.bindValue(":title", title);
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":author", author);
    query.bindValue(":release_year", release_year);
    query.bindValue(":limited_offer", limited_offer);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania zawartości:" << query.lastError().text();
    } else {
        qDebug() << "Zawartość dodana pomyślnie!";
    }
}

void Content::deleteContent() {
    if (title.isEmpty()) {
        QMessageBox::warning(nullptr, "Błąd", "Brak tytułu do usunięcia.");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM content WHERE title = :title");
    query.bindValue(":title", title);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Sukces", "Zawartość została usunięta.");

        title.clear();
        type.clear();
        category.clear();
        author.clear();
        release_year = 0;
        limited_offer = false;
    } else {
        QMessageBox::warning(nullptr, "Błąd", "Nie udało się usunąć zawartości.");
    }
}
