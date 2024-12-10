#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QMainWindow>
#include <QTableView>
#include <QSqlTableModel>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QVBoxLayout *layout = new QVBoxLayout(&w);

    // Connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("clement");
    db.setPassword("123456");

    if (db.open()) {
        qDebug() << "Vous êtes maintenant connecté à " << db.hostName();

        // Création d'un modèle pour afficher les données dans un QTableView
        QSqlTableModel *model = new QSqlTableModel();
        model->setTable("jeu");  // Assurez-vous que cette table existe dans votre base
        model->select();  // Exécute la requête pour récupérer les données

        // Création d'une vue pour afficher le modèle
        QTableView *view = new QTableView();
        view->setModel(model);
        view->resizeColumnsToContents();
        layout->addWidget(view);  // Ajouter le QTableView à la fenêtre
    }
    else
    {
        qDebug() << "La connexion a échouée, désolé";
    }

    w.setLayout(layout);
    w.show();

    return a.exec();
}
