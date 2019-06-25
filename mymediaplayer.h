#ifndef MYMEDIAPLAYER_H
#define MYMEDIAPLAYER_H

#include <QMediaPlayer>

class MyMediaPlayer : public QMediaPlayer
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ getVideoSurface WRITE setVideoSurface)

public:
    explicit MyMediaPlayer(QObject *parent = nullptr, Flags flags = 0);

    QAbstractVideoSurface* getVideoSurface() const;

public slots:
    void setVideoSurface(QAbstractVideoSurface* videoSurface);

private:
    QAbstractVideoSurface* m_videoSurface;
};

#endif // MYMEDIAPLAYER_H
