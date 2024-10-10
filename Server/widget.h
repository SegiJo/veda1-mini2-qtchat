#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onStartButtonClicked();   // "생성" 버튼 클릭 시 호출될 슬롯
    void onCloseButtonClicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;   // SQLite 데이터베이스 연결

    bool initializeDatabase();     // 데이터베이스 초기화 및 테이블 생성
    bool registerAdminAccount(const QString &username, const QString &password);  // 관리자 계정 등록
    bool validateAdminAccount(const QString &username, const QString &password);  // 관리자 계정 검증
};

#endif // WIDGET_H
