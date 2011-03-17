/***************************************************************************
 *   Copyright (C) 2011 by Pierre Marchand   *
 *   pierre@oep-h.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef RUGITEM_H
#define RUGITEM_H

#include <QGraphicsObject>
#include <QSize>
#include <QRectF>
#include <QString>

class ThreadPattern;

class RugItem : public QGraphicsObject
{
	Q_OBJECT

	const QString rugName;

	ThreadPattern * threadPattern;
	unsigned int threadHeight;
	QSize rugSize;

	int tmax;
	int nextStep(int base);

	QImage buffer;
	bool validBuffer;


	void fillBuffer();

	enum RugHandle
	{
		HandleNone,
		HandleRight,
		HandleBottom
	};

	RugHandle rugHandle;


public:
	explicit RugItem(const QString& name);

	QRectF boundingRect() const;
	void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );

	unsigned int getThreadHeight() const {return threadHeight;}
	void setThreadHeight(unsigned int t);

	ThreadPattern * getThreadPattern() const {return threadPattern;}
	void setThreadPattern(ThreadPattern * t);

	void setRugSize(QSize s);
	QSize getRugSize() const {return rugSize;}

	QString getRugName() const {return rugName;}

	QImage getBuffer(QSize s);

protected:
	bool isMoving;

	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent( QGraphicsSceneMouseEvent * event ) ;
	void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
	void rugSelected(const QString&);
	void changeSizeInteractive(QSize);
};

#endif // RUGITEM_H