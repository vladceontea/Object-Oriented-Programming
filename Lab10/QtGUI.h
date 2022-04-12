//
// Created by Vlad on 07/05/2021.
//

#ifndef A89_912_CEONTEA_VLADCALIN_QTGUI_H
#define A89_912_CEONTEA_VLADCALIN_QTGUI_H

#endif //A89_912_CEONTEA_VLADCALIN_QTGUI_H


#include "Validator.h"
#include "Exceptions.h"
#include <qwidget.h>
#include "Service.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include <QDialog>
#include <QMessageBox>
#include <QTableView>
#include <QShortcut>
#include "WatchlistTable.h"
#include "CommandManager.h"

class GUI: public QWidget{
    Q_OBJECT

public:

    GUI(std::vector<Tutorial> tutorials, QWidget *parent = nullptr);
    ~GUI();

private:

    std::vector<Tutorial> tutorials;

    std::vector<Tutorial> watchlist;

    CommandManager commandManager;

    QStackedWidget* windows;

    QListWidget* tutorialsList;
    QListWidget* tutorialsListTwo;

    QTableView* watchlistTableView;
    WatchlistTable* watchlistTableModel;

    QTextEdit* titleEdit;
    QLineEdit* presenterEdit;
    QLineEdit* durationEdit;
    QLineEdit* likesEdit;
    QTextEdit* linkEdit;

    QLineEdit* search;

    QPushButton* addTutorialButton;
    QPushButton* removeTutorialButton;
    QPushButton* updateTutorialButton;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QPushButton* exitApp;
    QPushButton* AdminMode;
    QPushButton* UserMode;
    QPushButton* addWatchlist;
    QPushButton* removeWatchlist;
    QPushButton* showWatchlist;
    QPushButton* exitAppTwo;

    void initGUI();
    void connectSignalAndSlots();
    void populateTutorialList();
    int getSelectedIndex();
    void getListItem();

    void addTutorialHandler();
    void removeTutorialHandler();
    void updateTutorialHandler();

    void addWatchlistHandler();
    void removeWatchlistHandler();

    void messageBox();

    void htmlDisplay();
    void csvDisplay();

signals:

    void tutorialsUpdatedSignal();
    void addTutorialSignal(const std::string& title, const std::string& presenter, const std::string& duration, const std::string& likes, const std::string& link);

public slots:

    void adminButton();

    void userButton();

    void exitButton();

    void addTutorial(const std::string& title, const std::string& presenter, const std::string& duration, const std::string& likes, const std::string& link);

    void undoButtonSlot();

    void redoButtonSlot();
};
