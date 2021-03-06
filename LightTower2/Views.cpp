
#include "Views.h"

void View::Setup()
{
  if(true == debugLEDs) Serial << "Setup View\n";
  SetupView();
}

void View::MergeSubViews()
{
  for(int v = 0; v < m_SubViews.size(); ++v)
  {
    View *aView = m_SubViews.get(v);
    PixelStruct &aPixelStruct = aView->GetPixelStruct();
    for(int x = 0; x < SCREEN_WIDTH; ++x)
    {
      for(int y = 0; y < SCREEN_HEIGHT; ++y)
      {
        if(true == debugLEDs) Serial << "Pixel Value " << "\tR:" << aPixelStruct.Pixel[x][y].red << "\tG:" << aPixelStruct.Pixel[x][y].green << "\tB:" << aPixelStruct.Pixel[x][y].blue << "\n";
        if( aPixelStruct.Pixel[x][y].red != 0 || aPixelStruct.Pixel[x][y].green != 0 || aPixelStruct.Pixel[x][y].blue != 0 )
        {
          switch(aView->GetMergeType())
          {
            case MergeType_Layer:
              if(true == debugLEDs) Serial << "Set Pixel " << x << "|" << y << " to: " << "\tR:" << aPixelStruct.Pixel[x][y].red << "\tG:" << aPixelStruct.Pixel[x][y].green << "\tB:" << aPixelStruct.Pixel[x][y].blue << "\n";
              m_MyPixelStruct.Pixel[x][y] = aPixelStruct.Pixel[x][y];
            break;
            case MergeType_Add:
              if(true == debugLEDs) Serial << "Set Pixel " << x << "|" << y << " to: " << "\tR:" << aPixelStruct.Pixel[x][y].red << "\tG:" << aPixelStruct.Pixel[x][y].green << "\tB:" << aPixelStruct.Pixel[x][y].blue << "\n";
              m_MyPixelStruct.Pixel[x][y].red = qadd8(aPixelStruct.Pixel[x][y].red, m_MyPixelStruct.Pixel[x][y].red);
              m_MyPixelStruct.Pixel[x][y].blue = qadd8(aPixelStruct.Pixel[x][y].blue, m_MyPixelStruct.Pixel[x][y].blue);
              m_MyPixelStruct.Pixel[x][y].green = qadd8(aPixelStruct.Pixel[x][y].green, m_MyPixelStruct.Pixel[x][y].green);
            break;
            default:
            break;
          }
        }
      }
    }
  }
}

void VerticalBarView::RunViewTask()
{
  m_ScaledHeight = (m_Y + round(m_HeightScalar*(float)m_H));
  if(m_ScaledHeight > m_Y + m_H) m_ScaledHeight = m_Y + m_H;
  if(true == debugLEDs) Serial << "Coords: " << m_X << "|" << m_Y << "|" << m_W << "|" << m_H << " Scaled Height: " << m_ScaledHeight << "\n";
  for(int x = 0; x<SCREEN_WIDTH; ++x)
  {
    for(int y = 0; y<SCREEN_HEIGHT; ++y)
    {
        m_MyPixelStruct.Pixel[x][y] = CRGB::Black;
      if( 
          (x >= m_X) && 
          (x < (m_X + m_W)) &&
          (y >= m_Y) && 
          (y < m_ScaledHeight)
        )
      {
        m_MyPixelStruct.Pixel[x][y] = m_Color;
      }
    }
  }
  if(true == debugLEDs) Serial << "\n";
  if(true == debugLEDs) Serial << "************\n";
  for(int y = 0; y < SCREEN_HEIGHT; ++y)
  {
    for(int x = 0; x < SCREEN_WIDTH; ++x)
    {
      CRGB bufColor = m_MyPixelStruct.Pixel[x][y];
      if(true == debugLEDs) Serial << bufColor.red << ":" << bufColor.green << ":" << bufColor.blue << " \t";
    }
    if(true == debugLEDs) Serial << "\n";
  }
}
void ScrollingView::RunViewTask()
{
  switch(m_ScrollDirection)
  {
    case ScrollDirection_Up:
      if(true == debugView) Serial << "Scroll Up\n";
      for(int x = 0; x < SCREEN_WIDTH; ++x)
      {
        for(int y = SCREEN_HEIGHT-1; y >= 0; --y)
        {
          if((x >= m_X) && (x < (m_X + m_W)) && (y > m_Y) && (y < (m_Y + m_H)))
          {
            if(true == debugView) Serial << x << "|" << y << ":S ";
            //Shift screen
            m_MyPixelStruct.Pixel[x][y] = m_MyPixelStruct.Pixel[x][y-1];
          }
          else
          {
            if(true == debugView) Serial << x << "|" << y << ":N ";
            //DO nothing
          }
        }
        if(true == debugView) Serial << "\n";
      }
      break;
    case ScrollDirection_Down:
      if(true == debugView) Serial << "Scroll Down\n";
      for(int x = 0; x < SCREEN_WIDTH; ++x)
      {
        for(int y = 0; y < SCREEN_HEIGHT; ++y)
        {
          if((x >= m_X) && (x < (m_X + m_W)) && (y >= m_Y) && (y < (m_Y + m_H - 1)))
          {
            if(true == debugView) Serial << x << "|" << y << ":S ";
            //Shift screen
            m_MyPixelStruct.Pixel[x][y] = m_MyPixelStruct.Pixel[x][y+1];
          }
          else
          {
            if(true == debugView) Serial << x << "|" << y << ":N ";
            //Do nothing
          }
        }
        if(true == debugView) Serial << "\n";
      }
      break;
    default:
    break;
  }
}
void ColorSpriteView::RunViewTask()
{
  if(true == debugView) Serial << "Coords: " << m_X << "|" << m_Y << "|" << m_W << "|" << m_H << "\n";
  for(int x = 0; x<SCREEN_WIDTH; ++x)
  {
    for(int y = 0; y<SCREEN_HEIGHT; ++y)
    {
        m_MyPixelStruct.Pixel[x][y] = CRGB::Black;
      if( 
          (x >= m_X) && 
          (x < (m_X + m_W)) &&
          (y >= m_Y) && 
          (y < (m_Y + m_H))
        )
      {
        m_MyPixelStruct.Pixel[x][y] = m_MyColor;
      }
    }
  }
}
