#ifndef CONTENT_H
#define CONTENT_H

#include <QString>

class Content {
public:
    Content(int content_id = 0, const QString &title = "", const QString &type = "",
            const QString &category = "", const QString &author = "",
            int release_year = 0, bool limited_offer = false, int view_count = 0);

    int getContentId() const;
    QString getTitle() const;
    QString getType() const;
    QString getCategory() const;
    QString getAuthor() const;
    int getReleaseYear() const;
    bool isLimitedOffer() const;
    int getViewCount() const;

    void setContentId(int id);
    void setTitle(const QString &title);
    void setType(const QString &type);
    void setCategory(const QString &category);
    void setAuthor(const QString &author);
    void setReleaseYear(int year);
    void setLimitedOffer(bool offer);

    void updateContent();
    void addContent();
    void deleteContent();

private:
    int content_id;
    QString title;
    QString type;
    QString category;
    QString author;
    int release_year;
    bool limited_offer;
    int view_count;
};

#endif // CONTENT_H
