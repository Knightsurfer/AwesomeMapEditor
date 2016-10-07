//////////////////////////////////////////////////////////////////////////////////
//
//
//                     d88b         888b           d888  888888888888
//                    d8888b        8888b         d8888  888
//                   d88''88b       888'8b       d8'888  888
//                  d88'  '88b      888 '8b     d8' 888  8888888
//                 d88Y8888Y88b     888  '8b   d8'  888  888
//                d88""""""""88b    888   '8b d8'   888  888
//               d88'        '88b   888    '888'    888  888
//              d88'          '88b  888     '8'     888  888888888888
//
//
// AwesomeMapEditor: A map editor for GBA Pokémon games.
// Copyright (C) 2016 Diegoisawesome, Pokedude
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//////////////////////////////////////////////////////////////////////////////////


#ifndef __AME_AMEBLOCKVIEW_HPP__
#define __AME_AMEBLOCKVIEW_HPP__


///////////////////////////////////////////////////////////
// Include files
//
///////////////////////////////////////////////////////////
#include <QtWidgets>
#include <QtOpenGL/QtOpenGL>
#include <QColor>
#include <AME/Widgets/OpenGL/AMEMapView.h>


namespace ame
{
    ///////////////////////////////////////////////////////////
    /// \file    AMEBlockView.h
    /// \author  Pokedude
    /// \version 1.0.0.0
    /// \date    6/18/2016
    /// \brief   Displays the primary and secondary blockset
    ///
    ///////////////////////////////////////////////////////////
    class AMEBlockView : public QOpenGLWidget, public QOpenGLFunctions {
    public:

        ///////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// Initializes AMEBlockView with a given parent.
        ///
        ///////////////////////////////////////////////////////////
        AMEBlockView(QWidget *parent = NULL);

        ///////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /// Destroys the OpenGL objects.
        ///
        ///////////////////////////////////////////////////////////
        ~AMEBlockView();


        ///////////////////////////////////////////////////////////
        /// \brief Copies all blocks to another AMEBlockView.
        ///
        ///////////////////////////////////////////////////////////
        void copyBlocks(AMEBlockView *other);


        ///////////////////////////////////////////////////////////
        /// \brief Retrieves pre-loaded data from the map view.
        ///
        ///////////////////////////////////////////////////////////
        void setMapView(AMEMapView *view);

        ///////////////////////////////////////////////////////////
        /// \brief Destroys all OpenGL resources.
        ///
        ///////////////////////////////////////////////////////////
        void freeGL();

        ///////////////////////////////////////////////////////////
        /// \brief Retrieves the selected blocks.
        ///
        ///////////////////////////////////////////////////////////
        QVector<UInt16> selectedBlocks();

        ///////////////////////////////////////////////////////////
        /// \brief Gets the current editor tool.
        ///
        ///////////////////////////////////////////////////////////
        AMEMapView::Tool getCurrentTool(Qt::MouseButtons buttons);

        ///////////////////////////////////////////////////////////
        /// \brief Sets the current editor tool.
        ///
        ///////////////////////////////////////////////////////////
        void setCurrentTool(AMEMapView::Tool newTool);

        ///////////////////////////////////////////////////////////
        /// \brief Selects a block and scrolls the view to meet it.
        ///
        ///////////////////////////////////////////////////////////
        void selectBlock(UInt16 newBlock);

        ///////////////////////////////////////////////////////////
        /// \brief Deselects the selected blocks in the case of
        /// the user picking from the map instead.
        ///
        ///////////////////////////////////////////////////////////
        void deselectBlocks();

    protected:

        ///////////////////////////////////////////////////////////
        /// \brief Initializes OpenGL-related things.
        ///
        ///////////////////////////////////////////////////////////
        void initializeGL();

        ///////////////////////////////////////////////////////////
        /// \brief Resizes the viewport and redraws the objects.
        ///
        ///////////////////////////////////////////////////////////
        void resizeGL(int w, int h);

        ///////////////////////////////////////////////////////////
        /// \brief Renders all the map textures.
        ///
        ///////////////////////////////////////////////////////////
        void paintGL();

        ///////////////////////////////////////////////////////////
        /// \brief Overrides the mouse press event.
        ///
        ///////////////////////////////////////////////////////////
        void mousePressEvent(QMouseEvent *event);

        ///////////////////////////////////////////////////////////
        /// \brief Overrides the mouse release event.
        ///
        ///////////////////////////////////////////////////////////
        void mouseReleaseEvent(QMouseEvent *event);

        ///////////////////////////////////////////////////////////
        /// \brief Overrides the mouse move event.
        ///
        ///////////////////////////////////////////////////////////
        void mouseMoveEvent(QMouseEvent *event);

        ///////////////////////////////////////////////////////////
        /// \brief Overrides the enter event.
        ///
        ///////////////////////////////////////////////////////////
        void enterEvent(QEvent *event);

        ///////////////////////////////////////////////////////////
        /// \brief Overrides the mouse leave event.
        ///
        ///////////////////////////////////////////////////////////
        void leaveEvent(QEvent *event);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        QList<UInt32> m_VertexBuffers;
        QList<UInt32> m_Textures;
        UInt32 m_PalTexture;
        UInt32 m_IndexBuffer;
        QVector<qboy::GLColor> *m_Palettes;
        QOpenGLVertexArrayObject m_VAO;
        QOpenGLShaderProgram m_Program;
        QOpenGLShaderProgram m_PmtProg;
        QSize m_PrimarySetSize;
        QSize m_SecondarySetSize;
        UInt8 *m_PrimaryForeground;
        UInt8 *m_PrimaryBackground;
        UInt8 *m_SecondaryForeground;
        UInt8 *m_SecondaryBackground;
        QVector<UInt16> m_SelectedBlocks;
        Int32 m_FirstBlock;
        Int32 m_LastBlock;
        Int32 m_HighlightedBlock;
        AMEMapView::Tool m_CurrentTool;
        QColor m_CursorColor;
        Boolean m_ShowHighlight;
    };
}


#endif //__AME_AMEBLOCKVIEW_HPP__
