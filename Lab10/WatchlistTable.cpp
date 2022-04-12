//
// Created by Vlad on 29/05/2021.
//

#include <QFont>
#include "WatchlistTable.h"

WatchlistTable::WatchlistTable(std::vector<Tutorial> watchlist): watchlist{watchlist} {}

int WatchlistTable::rowCount(const QModelIndex& parent) const
{
    return this->watchlist.size();
}

int WatchlistTable::columnCount(const QModelIndex& parent) const
{
    return 5;
}

QVariant WatchlistTable::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int column = index.column();

    if (role == Qt::DisplayRole)
    {
        if (column == 0)
        {
            std::string title = this->watchlist[row].getTitle();
            return QString::fromStdString(title);
        }
        if (column == 1)
        {
            std::string presenter = this->watchlist[row].getPresenter();
            return QString::fromStdString(presenter);
        }
        if (column == 2)
        {
            std::string duration = this->watchlist[row].getDuration();
            return QString::fromStdString(duration);
        }
        if (column == 3)
        {
            int likes = this->watchlist[row].getLikes();
            return QString::fromStdString(std::to_string(likes));
        }
        if (column == 4)
        {
            std::string link = this->watchlist[row].getLink();
            return QString::fromStdString(link);
        }
    }
    return QVariant();
}

QVariant WatchlistTable::headerData(int section, Qt::Orientation orientation, int role) const {

    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal){
            switch(section){
                case 0:
                    return QString{"Title"};
                case 1:
                    return QString{"Presenter"};
                case 2:
                    return QString{"Duration"};
                case 3:
                    return QString{"No. likes"};
                case 4:
                    return QString{"Link"};

                default:
                    break;
            }
        }
    }
    return QVariant();
}