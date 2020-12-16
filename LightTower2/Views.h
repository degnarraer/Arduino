    /*
    Light Tower by Rob Shockency
    Copyright (C) 2020 Rob Shockency degnarraer@yahoo.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version of the License, or
    (at your option) any later version. 3

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */
/**
 * @file LightTower2.ino
 * *

 */

#include "LEDControllerInterface.h"
#include "TaskInterface.h"
#include "Streaming.h"
#include "Tunes.h"
#include <LinkedList.h>

typedef int position;
typedef int size;

class View: public Task
{
  public:
    View(position X, position Y, size W, size H){}
    ~View()
    {
      if(true == debugMode && debugLevel >= 1) Serial << "Delete View\n";
    } 
    void SetPosition(position X, position Y){ m_X = X; m_Y = Y; }
    void SetSize(size W, size H){ m_W = W; m_H = H; }
    void AddChildView(View &Child){}
    void RemoveChildView(View &Child){}
    void RemoveAllChildrenViews(){}
  
  private:   
    position m_X;
    position m_Y;
    size m_W;
    size m_H;
    LinkedList<View*> ChildViews = LinkedList<View*>();
    View *ParentView;
    
    //Task
    void Setup(){ SetupView(); }
    bool CanRunMyTask(){ return CanRunViewTask(); }
    void RunTask(){ RunViewTask(); }

    //View
    virtual void SetupView() = 0;
    virtual bool CanRunViewTask() = 0;
    virtual void RunViewTask() = 0;
    
};


class VerticalBar: public View
{
  public:
    VerticalBar(): View(0, 0, 0, 0){}
    VerticalBar(position X, position Y, size W, size H): View(X, Y, W, H){}
    ~VerticalBar(){}
    void SetColor(CRGB Color){ m_Color = Color; }
    void SetNormalizedHeight(float Height) { m_Height = Height; }

  private:
    CRGB m_Color;
    float m_Height;

    //View
    void SetupView(){}
    bool CanRunViewTask(){}
    void RunViewTask(){}
};

class BassSprite: public View
{
  public:
    BassSprite(position X, position Y, size L, size W): View(X, Y, L, W){}
    ~BassSprite(){}

  private:
    //View
    void SetupView(){}
    bool CanRunViewTask(){}
    void RunViewTask(){}
};