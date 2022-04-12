//
// Created by Vlad on 07/05/2021.
//

#include "QtGUI.h"
#include <QDebug>
#include <iostream>

GUI::GUI(std::vector<Tutorial> _tutorials, QWidget* parent): QWidget{parent}, tutorials{_tutorials}
{
    this->initGUI();
    this->connectSignalAndSlots();
    this->populateTutorialList();
}

GUI::~GUI() {

}

void GUI::initGUI(){

    this->setWindowTitle("Master C++");
    QPalette pal;
    QColor col = {204, 255, 204};
    pal.setColor(QPalette::Background, col);
    this->setPalette(pal);

    QHBoxLayout* layout = new QHBoxLayout{ this };
    this->windows = new QStackedWidget{};

    QWidget* mainWidget = new QWidget{};
    QVBoxLayout* hLayout = new QVBoxLayout{ mainWidget };
    QFont f("Century Gothic", 12, QFont::Bold);
    this->AdminMode = new QPushButton("Administrator Mode");
    this->AdminMode->setFont(f);
    this->UserMode = new QPushButton("User Mode");
    this->UserMode->setFont(f);

    hLayout->addWidget(this->AdminMode);
    hLayout->addWidget(this->UserMode);

    windows->addWidget(mainWidget);

    QWidget* adminWidget = new QWidget{};
    QHBoxLayout* adminPageLayout = new QHBoxLayout{ adminWidget };


    this->tutorialsList = new QListWidget{};
    this->tutorialsList->setSelectionMode(QAbstractItemView::SingleSelection);
    adminPageLayout->addWidget(this->tutorialsList);

    QWidget* rightSide = new QWidget{};
    QVBoxLayout* adminTotalLayout = new QVBoxLayout{rightSide};

    QWidget* tutorialsData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{tutorialsData};

    this->titleEdit = new QTextEdit{};
    this->presenterEdit = new QLineEdit{};
    this->durationEdit = new QLineEdit{};
    this->likesEdit = new QLineEdit{};
    this->linkEdit = new QTextEdit{};

    QLabel* titleLabel = new QLabel{"&Title: "};
    titleLabel->setBuddy(this->titleEdit);
    QLabel* presenterLabel = new QLabel{"&Presenter: "};
    presenterLabel->setBuddy(this->presenterEdit);
    QLabel* durationLabel = new QLabel{"&Duration: "};
    durationLabel->setBuddy(this->durationEdit);
    QLabel* likesLabel = new QLabel{"&Likes: "};
    likesLabel->setBuddy(this->likesEdit);
    QLabel* linkLabel = new QLabel{"&Link: "};
    linkLabel->setBuddy(this->linkEdit);

    titleLabel->setFont(f);
    presenterLabel->setFont(f);
    durationLabel->setFont(f);
    likesLabel->setFont(f);
    linkLabel->setFont(f);

    this->titleEdit->setFont(f);
    this->presenterEdit->setFont(f);
    this->durationEdit->setFont(f);
    this->likesEdit->setFont(f);
    this->linkEdit->setFont(f);

    formLayout->addRow(titleLabel, this->titleEdit);
    formLayout->addRow(presenterLabel, this->presenterEdit);
    formLayout->addRow(durationLabel, this->durationEdit);
    formLayout->addRow(likesLabel, this->likesEdit);
    formLayout->addRow(linkLabel, this->linkEdit);

    adminTotalLayout->addWidget(tutorialsData);


    QWidget* buttonsWidget = new QWidget{};
    QVBoxLayout* adminLayout = new QVBoxLayout{ buttonsWidget };
    this->addTutorialButton = new QPushButton("Add tutorial");
    this->addTutorialButton->setFont(f);
    this->removeTutorialButton = new QPushButton("Remove tutorial");
    this->removeTutorialButton->setFont(f);
    this->updateTutorialButton = new QPushButton("Update tutorial");
    this->updateTutorialButton->setFont(f);
    this->exitApp = new QPushButton("Exit");
    this->exitApp->setFont(f);

    adminLayout->addWidget(this->addTutorialButton);
    adminLayout->addWidget(this->removeTutorialButton);
    adminLayout->addWidget(this->updateTutorialButton);
    adminLayout->addWidget(this->exitApp);

    adminTotalLayout->addWidget(buttonsWidget);

    adminPageLayout->addWidget(rightSide);

    windows->addWidget(adminWidget);


    QWidget* userWidget = new QWidget{};
    QHBoxLayout* userPageLayout = new QHBoxLayout{ userWidget };

    this->tutorialsListTwo = new QListWidget{};
    this->tutorialsListTwo->setSelectionMode(QAbstractItemView::SingleSelection);
    userPageLayout->addWidget(this->tutorialsListTwo);

    QWidget* userRight = new QWidget{};
    QVBoxLayout* userLayout = new QVBoxLayout{userRight};
    this->addWatchlist = new QPushButton("Add to watchlist");
    this->addWatchlist->setFont(f);
    this->removeWatchlist = new QPushButton("Remove from watchlist");
    this->removeWatchlist->setFont(f);
    this->showWatchlist = new QPushButton("Display the detailed watchlist");
    this->showWatchlist->setFont(f);
    this->exitAppTwo = new QPushButton("Exit");
    this->exitAppTwo->setFont(f);

    userLayout->addWidget(this->addWatchlist);
    userLayout->addWidget(this->removeWatchlist);
    userLayout->addWidget(this->showWatchlist);
    userLayout->addWidget(this->exitAppTwo);

    userPageLayout->addWidget(userRight);

    this->watchList = new QListWidget{};
    this->watchList->setSelectionMode(QAbstractItemView::SingleSelection);
    userPageLayout->addWidget(this->watchList);

    windows->addWidget(userWidget);

    layout->addWidget(windows);

}

void GUI::connectSignalAndSlots() {

    QObject::connect(this->AdminMode, SIGNAL(clicked()), this, SLOT(adminButton()));

    QObject::connect(this->UserMode, SIGNAL(clicked()), this, SLOT(userButton()));

    QObject::connect(this->exitApp, SIGNAL(clicked()), this, SLOT(exitButton()));

    QObject::connect(this->exitAppTwo, SIGNAL(clicked()), this, SLOT(exitButton()));

    QObject::connect(this->tutorialsList, &QListWidget::itemSelectionChanged, this, [this]() {this->getListItem(); });

    QObject::connect(this, &GUI::tutorialsUpdatedSignal, this, &GUI::populateTutorialList);

    QObject::connect(this->addTutorialButton, &QPushButton::clicked, this, &GUI::addTutorialHandler);

    QObject::connect(this->removeTutorialButton, &QPushButton::clicked, this, &GUI::removeTutorialHandler);

    QObject::connect(this, SIGNAL(addTutorialSignal(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &)), this, SLOT(addTutorial(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &)));


    QObject::connect(this->updateTutorialButton, &QPushButton::clicked, this, &GUI::updateTutorialHandler);

    QObject::connect(this->addWatchlist, &QPushButton::clicked, this, &GUI::addWatchlistHandler);

    QObject::connect(this->removeWatchlist, &QPushButton::clicked, this, &GUI::removeWatchlistHandler);

    QObject::connect(this->showWatchlist, &QPushButton::clicked, this, &GUI::messageBox);
}

void GUI::adminButton() {

    this->windows->setCurrentIndex(1);
}

void GUI::userButton(){

    this->windows->setCurrentIndex(2);
}
void GUI::exitButton(){

    this->close();
}

void GUI::populateTutorialList() {

    if(this->tutorialsList->count()>0){
        this->tutorialsList->clear();
    }
    if(this->tutorialsListTwo->count()>0){
        this->tutorialsListTwo->clear();
    }

    for(auto t: this->tutorials){

        QString itemInList = QString::fromStdString(t.getTitle());
        QString itemInListTwo = QString::fromStdString(t.getTitle());
        QFont f("Century Gothic", 12, QFont::Bold);
        QListWidgetItem* item = new QListWidgetItem{itemInList};
        QListWidgetItem* itemTwo = new QListWidgetItem{itemInListTwo};
        item->setFont(f);
        itemTwo->setFont(f);
        this->tutorialsList->addItem(item);
        this->tutorialsListTwo->addItem(itemTwo);

    }

    if(!this->tutorials.empty()){
        this->tutorialsList->setCurrentRow(0);
        this->tutorialsListTwo->setCurrentRow(0);
    }
}

int GUI::getSelectedIndex() {

    if(this->tutorialsList->count() == 0){
        return -1;
    }
    QModelIndexList index = this->tutorialsList->selectionModel()->selectedIndexes();

    if(index.size() == 0){
        this->titleEdit->clear();
        this->presenterEdit->clear();
        this->durationEdit->clear();
        this->likesEdit->clear();
        this->linkEdit->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void GUI::getListItem() {

    int idx = this->getSelectedIndex();
    if(idx == -1){
        return;
    }

    if(idx>= this->tutorials.size()){
        return;
    }

    Tutorial t = this->tutorials[idx];

    this->titleEdit->setText(QString::fromStdString(t.getTitle()));
    this->presenterEdit->setText(QString::fromStdString(t.getPresenter()));
    this->durationEdit->setText(QString::fromStdString(t.getDuration()));
    this->likesEdit->setText(QString::fromStdString(std::to_string(t.getLikes())));
    this->linkEdit->setText(QString::fromStdString(t.getLink()));
}

void GUI::addTutorial(const std::string &title, const std::string &presenter, const std::string &duration,
                      const std::string &likes, const std::string &link){

    int ok = 1;
    Validator valid;
    try{
        valid.valid_title(title);
        valid.valid_presenter(presenter);
        valid.valid_likes(likes);
        valid.valid_link(link);

    }
    catch (Exceptions &ex) {
        QMessageBox error;
        error.critical(0, "Error", "The input is invalid.");
        ok = 0;
    }

    if(ok==1){
        Tutorial t{title, presenter, duration, stoi(likes), link};
        this->tutorials.push_back(t);
        emit tutorialsUpdatedSignal();
    }
}

void GUI::addTutorialHandler() {

    QString title = this->titleEdit->toPlainText();
    QString presenter = this->presenterEdit->text();
    QString duration = this->durationEdit->text();
    QString likes = this->likesEdit->text();
    QString link = this->linkEdit->toPlainText();

    emit addTutorialSignal(title.toStdString(), presenter.toStdString(), duration.toStdString(), likes.toStdString(), link.toStdString());
}

void GUI::removeTutorialHandler() {

    int idx = this->getSelectedIndex();

    if(idx<0||idx>=this->tutorials.size()){
        return;
    }

    this->tutorials.erase(this->tutorials.begin()+idx);

    emit tutorialsUpdatedSignal();
}

void GUI::addWatchlistHandler() {

    QString title = this->tutorialsListTwo->currentItem()->text();
    std::string s_title = title.toStdString();
    for(auto t: this->tutorials){
        if(s_title == t.getTitle()){
            this->watchlist.push_back(t);
        }
    }
    this->watchList->addItem(this->tutorialsListTwo->takeItem(this->tutorialsListTwo->currentRow()));

}

void GUI::removeWatchlistHandler() {

    int idx = this->watchList->currentRow();

    if(idx<0||idx>=this->watchlist.size()){
        return;
    }

    this->watchlist.erase(this->watchlist.begin()+idx);

    this->tutorialsListTwo->addItem(this->watchList->takeItem(this->watchList->currentRow()));
}

void GUI::updateTutorialHandler() {

    int idx = this->getSelectedIndex();
    this->addTutorialHandler();

    this->tutorials.erase(this->tutorials.begin()+idx);

    emit tutorialsUpdatedSignal();
}

void GUI::messageBox() {

    QMessageBox format;
    format.setText("Choose how you want the list to be displayed.");

    QPushButton* htmlButton = format.addButton(tr("HTML"), QMessageBox::ActionRole);
    QPushButton* csvButton = format.addButton(tr("CSV"), QMessageBox::ActionRole);

    format.exec();

    if(format.clickedButton() == htmlButton){
        this->htmlDisplay();
    }
    else if (format.clickedButton() == csvButton){
        this->csvDisplay();
    }
}

void GUI::htmlDisplay() {

    std::ofstream f("Tutorials.html");

    if(!f.is_open()){
        return;
    }

    f<<"<!DOCTYPE html>"<<std::endl;
    f<<"<html>"<<std::endl;
    f<<"<head>"<<std::endl;
    f<<"    <title>Tutorials</title>"<<std::endl;
    f<<"</head>"<<std::endl;
    f<<"<body>"<<std::endl;
    f<<"<table border=\"1\">"<<std::endl;
    f<<"    <tr>"<<std::endl;
    f<<"        <td>Title</td>"<<std::endl;
    f<<"        <td>Presenter</td>"<<std::endl;
    f<<"        <td>Duration</td>"<<std::endl;
    f<<"        <td>Likes</td>"<<std::endl;
    f<<"        <td>Youtube link</td>"<<std::endl;
    f<<"    </tr>"<<std::endl;
    std::string text;
    for (auto& t: this->watchlist){
        f<<"    <tr>"<<std::endl;
        text = "        <td>" + t.getTitle() + "</td>";
        f<<text<<std::endl;
        text = "        <td>" + t.getPresenter() + "</td>";
        f<<text<<std::endl;
        text = "        <td>" + t.getDuration() + "</td>";
        f<<text<<std::endl;
        text = "        <td>" + std::to_string(t.getLikes()) + "</td>";
        f<<text<<std::endl;
        text = "        <td><a href=\"" + t.getLink() + "\">Link</a></td>";
        f<<text<<std::endl;
    }
    f<<"</table>"<<std::endl;
    f<<"</body>"<<std::endl;
    f<<"</html>"<<std::endl;
    f.close();

    std::string topic = "Tutorials.html";
    system(topic.c_str());
}

void GUI::csvDisplay() {
    std::ofstream f("Tutorials.csv");
    if(!f.is_open()){
        return;
    }
    for (const auto& t: this->watchlist){
        f<<t;
    }
    f.close();

    std::string topic = "Tutorials.csv";
    system(topic.c_str());
}