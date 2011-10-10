/*
 *  This file is part of KIMToy, an input method frontend for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License or (at your option) version 3 or any later version
 *  accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 *  defined in Section 14 of version 3 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef THEMELISTVIEW_H
#define THEMELISTVIEW_H

#include <QListView>

class ThemeListView : public QListView
{
    Q_OBJECT
    Q_PROPERTY(QString themeUri READ themeUri WRITE setThemeUri USER true)
    public:
        explicit ThemeListView( QWidget* parent = 0 );
        virtual ~ThemeListView();
        QString themeUri() const;
        void setThemeUri( const QString& themeUri );
    public Q_SLOTS:
        void refresh();
    Q_SIGNALS:
        void themeUriChanged( const QString& newThemeUri );
    protected:
        virtual void resizeEvent( QResizeEvent* event );
    private Q_SLOTS:
        void slotCurrentChanged( const QModelIndex& current, const QModelIndex& previous );
        void relayout();
    private:
        void adaptSize();
    private:
        QString m_themeUri;
};

#endif // THEMELISTVIEW_H
