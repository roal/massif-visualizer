/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include <KLocalizedString>
#include <KAboutData>
#include <KApplication>
#include <KCmdLineArgs>
#include <KCmdLineOptions>
#include <KUrl>

#include <QTextStream>
#include <QFile>

#include "massifdata/parser.h"
#include "massifdata/filedata.h"
#include "massifdata/snapshotitem.h"

#include "visualizer/costmodel.h"

#include "KDChartPlotter"

#include <QtCore/QDebug>

#include "mainwindow.h"

int main( int argc, char *argv[] )
{
    KAboutData aboutData( "massif-visualizer", 0, ki18n( "Massif Visualizer" ),
                          i18n("0.1").toUtf8(), ki18n("A visualizer for output generated by Valgrind's massif tool."), KAboutData::License_LGPL,
                          ki18n( "Copyright 2010, Milian Wolff <mail@milianw.de>" ) );

    KCmdLineArgs::init( argc, argv, &aboutData, KCmdLineArgs::CmdLineArgNone );
    KCmdLineOptions options;
    options.add("+file", ki18n("Opens given output file and visualize it."));

    KCmdLineArgs::addCmdLineOptions( options );
    KCmdLineArgs* args = KCmdLineArgs::parsedArgs();
    KApplication app;

    Massif::MainWindow* window = new Massif::MainWindow;
    if (args->count()) {
        window->openFile(args->url(0));
    }
    window->show();
    return app.exec();
}
