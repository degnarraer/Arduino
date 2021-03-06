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

#ifndef VisualizationFactory_H
#define VisualizatiosnFactory_H

#include "Visualization.h"

//********* VUMeter *********
class VUMeter: public Visualization
{
  public:
    VUMeter( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~VUMeter()
    {
      if(true == debugMemory) Serial << "VUMeter: Deleted";
    }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:
    SoundPowerModel m_SoundPower = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    RandomColorFadingModel m_ColorModel = RandomColorFadingModel("Color Model", 5000);
    VerticalBarView m_VerticalBar = VerticalBarView("Vertical Bar", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MergeType_Add);
    GravitationalModel m_GravitationalModel = GravitationalModel("GravitationalModel0", 0.1, 0.0);
    ColorSpriteView m_PeakSprite = ColorSpriteView("PeakSprite", 0, 30, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
};

//********* 8 Band VUMeter *********
class VUMeter8Band: public Visualization
{
  public:
    VUMeter8Band( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~VUMeter8Band()
    {
      if(true == debugMemory) Serial << "VUMeter8Band: Deleted";
    }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:
    float numVisualizations = 8.0;
    VerticalBarView m_VerticalBar0 = VerticalBarView("Vertical Bar 0", 0, 0*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower0 = ReducedBandsBandPowerModel("Sound Power Model 0", 0, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel0 = RainbowColorModel("Color Model 0", 0, numVisualizations);
    GravitationalModel m_GravitationalModel0 = GravitationalModel("GravitationalModel0", 0.1, 0.0);
    ColorSpriteView m_PeakSprite0 = ColorSpriteView("PeakSprite0", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar1 = VerticalBarView("Vertical Bar 1", 0, 1*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower1 = ReducedBandsBandPowerModel("Sound Power Model 1", 1, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel1 = RainbowColorModel("Color Model 1", 1, numVisualizations);
    GravitationalModel m_GravitationalModel1 = GravitationalModel("GravitationalModel1", 0.1, 0.0);
    ColorSpriteView m_PeakSprite1 = ColorSpriteView("PeakSprite1", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar2 = VerticalBarView("Vertical Bar 2", 0, 2*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower2 = ReducedBandsBandPowerModel("Sound Power Model 2", 2, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel2 = RainbowColorModel("Color Model 2", 2, numVisualizations);
    GravitationalModel m_GravitationalModel2 = GravitationalModel("GravitationalModel2", 0.1, 0.0);
    ColorSpriteView m_PeakSprite2 = ColorSpriteView("PeakSprite2", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar3 = VerticalBarView("Vertical Bar 3", 0, 3*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower3 = ReducedBandsBandPowerModel("Sound Power Model 3", 3, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel3 = RainbowColorModel("Color Model 3", 3, numVisualizations);
    GravitationalModel m_GravitationalModel3 = GravitationalModel("GravitationalModel3", 0.1, 0.0);
    ColorSpriteView m_PeakSprite3 = ColorSpriteView("PeakSprite3", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar4 = VerticalBarView("Vertical Bar 4", 0, 4*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower4 = ReducedBandsBandPowerModel("Sound Power Model 4", 4, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel4 = RainbowColorModel("Color Model 4", 4, numVisualizations);
    GravitationalModel m_GravitationalModel4 = GravitationalModel("GravitationalModel2", 0.1, 0.0);
    ColorSpriteView m_PeakSprite4 = ColorSpriteView("PeakSprite4", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar5 = VerticalBarView("Vertical Bar 5", 0, 5*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower5 = ReducedBandsBandPowerModel("Sound Power Model 5", 5, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel5 = RainbowColorModel("Color Model 5", 5, numVisualizations);
    GravitationalModel m_GravitationalModel5 = GravitationalModel("GravitationalModel5", 0.1, 0.0);
    ColorSpriteView m_PeakSprite5 = ColorSpriteView("PeakSprite5", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar6 = VerticalBarView("Vertical Bar 6", 0, 6*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower6 = ReducedBandsBandPowerModel("Sound Power Model 6", 6, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel6 = RainbowColorModel("Color Model 6", 6, numVisualizations);
    GravitationalModel m_GravitationalModel6 = GravitationalModel("GravitationalModel6", 0.1, 0.0);
    ColorSpriteView m_PeakSprite6 = ColorSpriteView("PeakSprite6", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar7 = VerticalBarView("Vertical Bar 7", 0, 7*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower7 = ReducedBandsBandPowerModel("Sound Power Model 7", 7, 5, numVisualizations, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel7 = RainbowColorModel("Color Model 7", 7, numVisualizations);
    GravitationalModel m_GravitationalModel7 = GravitationalModel("GravitationalModel7", 0.1, 0.0);
    ColorSpriteView m_PeakSprite7 = ColorSpriteView("PeakSprite7", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
};

//********* 3 Band VUMeter *********
class VUMeter3Band: public Visualization
{
  public:
    VUMeter3Band( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~VUMeter3Band()
    {
      if(true == debugMemory) Serial << "VUMeter3Band: Deleted";
    }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:
    float numVisualizations = 3.0;
    VerticalBarView m_VerticalBar0 = VerticalBarView("Vertical Bar 0", 0, 0*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower0 = ReducedBandsBandPowerModel("Sound Power Model 0", 0, 5, 3, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel0 = RainbowColorModel("Color Model 0", 0, numVisualizations);
    GravitationalModel m_GravitationalModel0 = GravitationalModel("GravitationalModel0", 0.1, 0.0);
    ColorSpriteView m_PeakSprite0 = ColorSpriteView("PeakSprite0", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar1 = VerticalBarView("Vertical Bar 1", 0, 1*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower1 = ReducedBandsBandPowerModel("Sound Power Model 1", 1, 5, 3, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel1 = RainbowColorModel("Color Model 1", 1, numVisualizations);
    GravitationalModel m_GravitationalModel1 = GravitationalModel("GravitationalModel1", 0.1, 0.0);
    ColorSpriteView m_PeakSprite1 = ColorSpriteView("PeakSprite1", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
    
    VerticalBarView m_VerticalBar2 = VerticalBarView("Vertical Bar 2", 0, 2*SCREEN_HEIGHT/numVisualizations, SCREEN_WIDTH, SCREEN_HEIGHT/numVisualizations, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower2 = ReducedBandsBandPowerModel("Sound Power Model 2", 2, 5, 3, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel2 = RainbowColorModel("Color Model 2", 2, numVisualizations);
    GravitationalModel m_GravitationalModel2 = GravitationalModel("GravitationalModel2", 0.1, 0.0);
    ColorSpriteView m_PeakSprite2 = ColorSpriteView("PeakSprite2", 0, 0, SCREEN_WIDTH, 1, CRGB::Red, MergeType_Add);
};

//********* Waterfall *********
class Waterfall: public Visualization
{
  public:
    Waterfall( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
             : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~Waterfall() { if(true == debugMemory) Serial << "Waterfall: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:
    ScrollingView m_ScrollingView = ScrollingView("Scrolling View", ScrollDirection_Down, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    ColorSpriteView m_Sprite0 = ColorSpriteView("Sprite", 0, SCREEN_HEIGHT - 1, 4, 1);
    SoundPowerModel m_PowerModel = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    RandomColorFadingModel m_ColorModel = RandomColorFadingModel("Color Fading Model", 10000);
    SettableColorPowerModel m_PowerColorModel = SettableColorPowerModel("Settable Power Model");
};

//********* Fire *********
class Fire: public Visualization
{
  public:
    Fire( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
        : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~Fire(){ if(true == debugMemory) Serial << "Fire: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:    
    ScrollingView m_ScrollingView = ScrollingView("Scrolling View", ScrollDirection_Up, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    ColorSpriteView m_Sprite0 = ColorSpriteView("Sprite", 0, 0, 4, 1);
    SoundPowerModel m_PowerModel = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    RandomColorFadingModel m_ColorModel = RandomColorFadingModel("Color Fading Model", 10000);
    SettableColorPowerModel m_PowerColorModel = SettableColorPowerModel("Settable Power Model");
};

//********* WaterFireFromCenter *********
class WaterFireFromCenter: public Visualization
{
  public:
    WaterFireFromCenter( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                       : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~WaterFireFromCenter() { if(true == debugMemory) Serial << "Fire: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:
    ScrollingView m_ScrollingView0 = ScrollingView("Fire Scrolling View", ScrollDirection_Up, 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2);
    ColorSpriteView m_Sprite0 = ColorSpriteView("Fire Sprite 0", 0, SCREEN_HEIGHT/2, 4, 1);
    SoundPowerModel m_PowerModel0 = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    RandomColorFadingModel m_ColorModel0 = RandomColorFadingModel("Color Fading Model", 10000);
    SettableColorPowerModel m_PowerColorModel0 = SettableColorPowerModel("Settable Power Model");
    
    ScrollingView m_ScrollingView1 = ScrollingView("Water Scrolling View", ScrollDirection_Down, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT/2);
    ColorSpriteView m_Sprite1 = ColorSpriteView("Water Sprite 0", 0, SCREEN_HEIGHT/2-1, 4, 1);
    SoundPowerModel m_PowerModel1 = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    RandomColorFadingModel m_ColorModel1 = RandomColorFadingModel("Color Fading Model", 10000);
    SettableColorPowerModel m_PowerColorModel1 = SettableColorPowerModel("Settable Power Model");
};

//********* WaterFireFromEdge *********
class WaterFireFromEdge: public Visualization
{
  public:
    WaterFireFromEdge( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                       : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~WaterFireFromEdge() { if(true == debugMemory) Serial << "Fire: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:
    ScrollingView m_ScrollingView0 = ScrollingView("Fire Scrolling View", ScrollDirection_Up, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    FadingView m_FadingView0 = FadingView("FadingView 0", SCREEN_HEIGHT, Direction_Up, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MergeType_Add);
    ColorSpriteView m_Sprite0 = ColorSpriteView("Fire Sprite 0", 0, 0, 4, 1);
    SoundPowerModel m_PowerModel0 = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    RandomColorFadingModel m_ColorModel0 = RandomColorFadingModel("Color Fading Model", 10000);
    SettableColorPowerModel m_PowerColorModel0 = SettableColorPowerModel("Settable Power Model");
    
    ScrollingView m_ScrollingView1 = ScrollingView("Water Scrolling View", ScrollDirection_Down, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    FadingView m_FadingView1 = FadingView("FadingView 1", SCREEN_HEIGHT, Direction_Down, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MergeType_Add);
    ColorSpriteView m_Sprite1 = ColorSpriteView("Water Sprite 0", 0, SCREEN_HEIGHT-1, 4, 1);
    SoundPowerModel m_PowerModel1 = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    RandomColorFadingModel m_ColorModel1 = RandomColorFadingModel("Color Fading Model", 10000);
    SettableColorPowerModel m_PowerColorModel1 = SettableColorPowerModel("Settable Power Model");
};

//********* Vertical Band Tower *********
class VerticalBandTower: public Visualization
{
  public:
    VerticalBandTower( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                     : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~VerticalBandTower(){ if(true == debugMemory) Serial << "VerticalBandTower: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:  
};

//********* scrolling Bands *********
class ScrollingBands: public Visualization
{
  public:
    ScrollingBands( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                  : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~ScrollingBands(){ if(true == debugMemory) Serial << "VerticalBandTower: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:
  
    ScrollingView m_ScrollingView0 = ScrollingView("Upward Scrolling View", ScrollDirection_Up, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    FadingView m_FadingView0 = FadingView("FadingView 0", SCREEN_HEIGHT, Direction_Up, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MergeType_Add);
    ScrollingView m_ScrollingView1 = ScrollingView("Downward Scrolling View", ScrollDirection_Down, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    FadingView m_FadingView1 = FadingView("FadingView 1", SCREEN_HEIGHT, Direction_Down, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MergeType_Add);
    
    ColorSpriteView m_Sprite0 = ColorSpriteView("Sprite 0", 0, 0, 1, 1);
    ReducedBandsBandPowerModel m_BandPower0 = ReducedBandsBandPowerModel("Sound Power Model 0", 0, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel0 = RainbowColorModel("Color Model 1", 0, 8);
    SettableColorPowerModel m_PowerColorModel0 = SettableColorPowerModel("Settable Power Model");
    
    ColorSpriteView m_Sprite1 = ColorSpriteView("Sprite 0", 1, 0, 1, 1);
    ReducedBandsBandPowerModel m_BandPower1 = ReducedBandsBandPowerModel("Sound Power Model 1", 1, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel1 = RainbowColorModel("Color Model 1", 1, 8);
    SettableColorPowerModel m_PowerColorModel1 = SettableColorPowerModel("Settable Power Model");
    
    ColorSpriteView m_Sprite2 = ColorSpriteView("Sprite 0", 2, 0, 1, 1);
    ReducedBandsBandPowerModel m_BandPower2 = ReducedBandsBandPowerModel("Sound Power Model 2", 2, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel2 = RainbowColorModel("Color Model 1", 2, 8);
    SettableColorPowerModel m_PowerColorModel2 = SettableColorPowerModel("Settable Power Model");
    
    ColorSpriteView m_Sprite3 = ColorSpriteView("Sprite 0", 3, 0, 1, 1);
    ReducedBandsBandPowerModel m_BandPower3 = ReducedBandsBandPowerModel("Sound Power Model 3", 3, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel3 = RainbowColorModel("Color Model 1", 3, 8);
    SettableColorPowerModel m_PowerColorModel3 = SettableColorPowerModel("Settable Power Model");

    
    ColorSpriteView m_Sprite4 = ColorSpriteView("Sprite 0", 0, SCREEN_HEIGHT - 1, 1, 1);
    ReducedBandsBandPowerModel m_BandPower4 = ReducedBandsBandPowerModel("Sound Power Model 0", 4, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel4 = RainbowColorModel("Color Model 1", 4, 8);
    SettableColorPowerModel m_PowerColorModel4 = SettableColorPowerModel("Settable Power Model");
    
    ColorSpriteView m_Sprite5 = ColorSpriteView("Sprite 0", 1, SCREEN_HEIGHT - 1, 1, 1);
    ReducedBandsBandPowerModel m_BandPower5 = ReducedBandsBandPowerModel("Sound Power Model 1", 5, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel5 = RainbowColorModel("Color Model 1", 5, 8);
    SettableColorPowerModel m_PowerColorModel5 = SettableColorPowerModel("Settable Power Model");
    
    ColorSpriteView m_Sprite6 = ColorSpriteView("Sprite 0", 2, SCREEN_HEIGHT - 1, 1, 1);
    ReducedBandsBandPowerModel m_BandPower6 = ReducedBandsBandPowerModel("Sound Power Model 2", 6, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel6 = RainbowColorModel("Color Model 1", 6, 8);
    SettableColorPowerModel m_PowerColorModel6 = SettableColorPowerModel("Settable Power Model");
    
    ColorSpriteView m_Sprite7 = ColorSpriteView("Sprite 0", 3, SCREEN_HEIGHT - 1, 1, 1);
    ReducedBandsBandPowerModel m_BandPower7 = ReducedBandsBandPowerModel("Sound Power Model 3", 7, 0, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel7 = RainbowColorModel("Color Model 1", 7, 8);
    SettableColorPowerModel m_PowerColorModel7 = SettableColorPowerModel("Settable Power Model"); 
};

//********* Scrolling Max Band *********
class ScrollingMaxBand: public Visualization
{
  public:
    ScrollingMaxBand( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                    : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~ScrollingMaxBand(){ if(true == debugMemory) Serial << "ScrollingMaxBand: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController);
    void SetupVisualization();
    bool CanRunVisualization();
    void RunVisualization();
  private:    
    ScrollingView m_ScrollingView = ScrollingView("Scrolling View", ScrollDirection_Up, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    ColorSpriteView m_Sprite0 = ColorSpriteView("Sprite", 0, 0, 4, 1);
    BandDataColorModel m_BandDataColorModel = BandDataColorModel( "Band Data Color Model" );
    MaximumBandModel m_MaxBandModel = MaximumBandModel( "Max Band Model", 0, m_StatisticalEngineModelInterface );
};

//********* Rotating View *********
class RotatingSprites: public Visualization
{
  public:
    RotatingSprites( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
                   : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~RotatingSprites(){ if(true == debugMemory) Serial << "ScrollingMaxBand: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController)
    {
      if(true == debugMemory) Serial << "RotatingSprites: Get Instance\n";
      RotatingSprites *vis = new RotatingSprites(StatisticalEngineModelInterface, LEDController);
      return vis; 
    }
    void SetupVisualization()
    {
      AddModel(m_PowerModel0);
      
      AddModel(m_ColorModel0);
      AddModel(m_ColorModel1);
      AddModel(m_ColorModel2);
      AddModel(m_ColorModel3);
      
      AddModel(m_PowerColorModel0);
      AddModel(m_PowerColorModel1);
      AddModel(m_PowerColorModel2);
      AddModel(m_PowerColorModel3);

      m_PowerColorModel0.ConnectColorModel(m_ColorModel0);
      m_PowerColorModel1.ConnectColorModel(m_ColorModel1);
      m_PowerColorModel2.ConnectColorModel(m_ColorModel2);
      m_PowerColorModel3.ConnectColorModel(m_ColorModel3);

      m_PowerColorModel0.ConnectPowerModel(m_PowerModel0);
      m_PowerColorModel1.ConnectPowerModel(m_PowerModel0);
      m_PowerColorModel2.ConnectPowerModel(m_PowerModel0);
      m_PowerColorModel3.ConnectPowerModel(m_PowerModel0);

      m_Sprite0.ConnectColorModel(m_PowerColorModel0);
      m_Sprite1.ConnectColorModel(m_PowerColorModel1);
      m_Sprite2.ConnectColorModel(m_PowerColorModel2);
      m_Sprite3.ConnectColorModel(m_PowerColorModel3);
      
      m_RotateView0.AddSubView(m_Sprite0);
      m_RotateView0.AddSubView(m_Sprite1);
      m_RotateView0.AddSubView(m_Sprite2);
      m_RotateView0.AddSubView(m_Sprite3);
      AddView(m_RotateView0);
    }
    bool CanRunVisualization(){ return true; }
    void RunVisualization(){}
  private:
    SoundPowerModel m_PowerModel0 = SoundPowerModel("Sound Power Model", m_StatisticalEngineModelInterface);
    ColorSpriteView m_Sprite0 = ColorSpriteView("Sprite 0", 0, 0, 1, 1);
    ColorSpriteView m_Sprite1 = ColorSpriteView("Sprite 1", 1, 0, 1, 1);
    ColorSpriteView m_Sprite2 = ColorSpriteView("Sprite 2", 2, 0, 1, 1);
    ColorSpriteView m_Sprite3 = ColorSpriteView("Sprite 3", 3, 0, 1, 1);
    RandomColorFadingModel m_ColorModel0 = RandomColorFadingModel("Color Fading Model 0", 10000);
    RandomColorFadingModel m_ColorModel1 = RandomColorFadingModel("Color Fading Model 1", 10000);
    RandomColorFadingModel m_ColorModel2 = RandomColorFadingModel("Color Fading Model 2", 10000);
    RandomColorFadingModel m_ColorModel3 = RandomColorFadingModel("Color Fading Model 3", 10000);
    SettableColorPowerModel m_PowerColorModel0 = SettableColorPowerModel("Settable Power Model 0");
    SettableColorPowerModel m_PowerColorModel1 = SettableColorPowerModel("Settable Power Model 1");
    SettableColorPowerModel m_PowerColorModel2 = SettableColorPowerModel("Settable Power Model 2");
    SettableColorPowerModel m_PowerColorModel3 = SettableColorPowerModel("Settable Power Model 3");
    RotatingView m_RotateView0 = RotatingView("Rotating View 0", Direction_Up, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MergeType_Layer);;
};

//********* Ball Shooter *********
class BallShooter: public Visualization
{
  public:
    BallShooter( StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController) 
               : Visualization( StatisticalEngineModelInterface, LEDController){}
    virtual ~BallShooter(){ if(true == debugMemory) Serial << "BallShooter: Deleted"; }

    //Visualization
    static Visualization* GetInstance(StatisticalEngineModelInterface &StatisticalEngineModelInterface, LEDController &LEDController)
    {
      if(true == debugMemory) Serial << "BallShooter: Get Instance\n";
      BallShooter *vis = new BallShooter(StatisticalEngineModelInterface, LEDController);
      return vis; 
    }
    void SetupVisualization()
    {
      AddView(m_VerticalBar0);
      AddView(m_PeakSprite0);
      AddModel(m_BandPower0);
      AddModel(m_ColorModel0);
      AddModel(m_VerticalBar0);
      AddModel(m_GravitationalModel0);
      m_VerticalBar0.ConnectBarHeightModel(m_BandPower0);
      m_VerticalBar0.ConnectBarColorModel(m_ColorModel0);
      m_PeakSprite0.ConnectPositionModel(m_GravitationalModel0);
      m_GravitationalModel0.ConnectPositionModel(m_VerticalBar0);
      m_PeakSprite0.ConnectColorModel(m_ColorModel0); 
      
      AddView(m_VerticalBar1);
      AddView(m_PeakSprite1);
      AddModel(m_BandPower1);
      AddModel(m_ColorModel1);
      AddModel(m_VerticalBar1);
      AddModel(m_GravitationalModel1);
      m_VerticalBar1.ConnectBarHeightModel(m_BandPower1);
      m_VerticalBar1.ConnectBarColorModel(m_ColorModel1);
      m_PeakSprite1.ConnectPositionModel(m_GravitationalModel1);
      m_GravitationalModel1.ConnectPositionModel(m_VerticalBar1);
      m_PeakSprite1.ConnectColorModel(m_ColorModel1);
      
      AddView(m_VerticalBar2);
      AddView(m_PeakSprite2);
      AddModel(m_BandPower2);
      AddModel(m_ColorModel2);
      AddModel(m_VerticalBar2);
      AddModel(m_GravitationalModel2);
      m_VerticalBar2.ConnectBarHeightModel(m_BandPower2);
      m_VerticalBar2.ConnectBarColorModel(m_ColorModel2);
      m_PeakSprite2.ConnectPositionModel(m_GravitationalModel2);
      m_GravitationalModel2.ConnectPositionModel(m_VerticalBar2);
      m_PeakSprite2.ConnectColorModel(m_ColorModel2);
      
      AddView(m_VerticalBar3);
      AddView(m_PeakSprite3);
      AddModel(m_BandPower3);
      AddModel(m_ColorModel3);
      AddModel(m_VerticalBar3);
      AddModel(m_GravitationalModel3);
      m_VerticalBar3.ConnectBarHeightModel(m_BandPower3);
      m_VerticalBar3.ConnectBarColorModel(m_ColorModel3);
      m_PeakSprite3.ConnectPositionModel(m_GravitationalModel3);
      m_GravitationalModel3.ConnectPositionModel(m_VerticalBar3);
      m_PeakSprite3.ConnectColorModel(m_ColorModel3);
      
      AddView(m_VerticalBar4);
      AddView(m_PeakSprite4);
      AddModel(m_BandPower4);
      AddModel(m_ColorModel4);
      AddModel(m_VerticalBar4);
      AddModel(m_GravitationalModel4);
      m_VerticalBar4.ConnectBarHeightModel(m_BandPower4);
      m_VerticalBar4.ConnectBarColorModel(m_ColorModel4);
      m_PeakSprite4.ConnectPositionModel(m_GravitationalModel4);
      m_GravitationalModel4.ConnectPositionModel(m_VerticalBar4);
      m_PeakSprite4.ConnectColorModel(m_ColorModel4);
      
      AddView(m_VerticalBar5);
      AddView(m_PeakSprite5);
      AddModel(m_BandPower5);
      AddModel(m_ColorModel5);
      AddModel(m_VerticalBar5);
      AddModel(m_GravitationalModel5);
      m_VerticalBar5.ConnectBarHeightModel(m_BandPower5);
      m_VerticalBar5.ConnectBarColorModel(m_ColorModel5);
      m_PeakSprite5.ConnectPositionModel(m_GravitationalModel5);
      m_GravitationalModel5.ConnectPositionModel(m_VerticalBar5);
      m_PeakSprite5.ConnectColorModel(m_ColorModel5);
      
      AddView(m_VerticalBar6);
      AddView(m_PeakSprite6);
      AddModel(m_BandPower6);
      AddModel(m_ColorModel6);
      AddModel(m_VerticalBar6);
      AddModel(m_GravitationalModel6);
      m_VerticalBar6.ConnectBarHeightModel(m_BandPower6);
      m_VerticalBar6.ConnectBarColorModel(m_ColorModel6);
      m_PeakSprite6.ConnectPositionModel(m_GravitationalModel6);
      m_GravitationalModel6.ConnectPositionModel(m_VerticalBar6);
      m_PeakSprite6.ConnectColorModel(m_ColorModel6);
      
      AddView(m_VerticalBar7);
      AddView(m_PeakSprite7);
      AddModel(m_BandPower7);
      AddModel(m_ColorModel7);
      AddModel(m_VerticalBar7);
      AddModel(m_GravitationalModel7);
      m_VerticalBar7.ConnectBarHeightModel(m_BandPower7);
      m_VerticalBar7.ConnectBarColorModel(m_ColorModel7);
      m_PeakSprite7.ConnectPositionModel(m_GravitationalModel7);
      m_PeakSprite7.ConnectColorModel(m_ColorModel7);
      m_GravitationalModel7.ConnectPositionModel(m_VerticalBar7); 
    }
    bool CanRunVisualization(){ return true; }
    void RunVisualization(){}
  private:
    VerticalBarView m_VerticalBar0 = VerticalBarView("Vertical Bar 0", 0, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite0 = ColorSpriteView("PeakSprite0", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower0 = ReducedBandsBandPowerModel("Sound Power Model 0", 0, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel0 = RainbowColorModel("Color Model 0", 0, 8);
    GravitationalModel m_GravitationalModel0 = GravitationalModel("GravitationalModel0", 1.0, 10.0);
    
    VerticalBarView m_VerticalBar1 = VerticalBarView("Vertical Bar 1", 0, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite1 = ColorSpriteView("PeakSprite1", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower1 = ReducedBandsBandPowerModel("Sound Power Model 1", 1, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel1 = RainbowColorModel("Color Model 1", 1, 8);
    GravitationalModel m_GravitationalModel1 = GravitationalModel("GravitationalModel1", 1.0, 10.0);
    
    VerticalBarView m_VerticalBar2 = VerticalBarView("Vertical Bar 2", 1, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite2 = ColorSpriteView("PeakSprite2", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower2 = ReducedBandsBandPowerModel("Sound Power Model 2", 2, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel2 = RainbowColorModel("Color Model 2", 2, 8);
    GravitationalModel m_GravitationalModel2 = GravitationalModel("GravitationalModel2", 1.0, 10.0);
    
    VerticalBarView m_VerticalBar3 = VerticalBarView("Vertical Bar 3", 1, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite3 = ColorSpriteView("PeakSprite3", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower3 = ReducedBandsBandPowerModel("Sound Power Model 3", 3, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel3 = RainbowColorModel("Color Model 3", 3, 8);
    GravitationalModel m_GravitationalModel3 = GravitationalModel("GravitationalModel3", 1.0, 10.0);
    
    VerticalBarView m_VerticalBar4 = VerticalBarView("Vertical Bar 4", 2, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite4 = ColorSpriteView("PeakSprite4", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower4 = ReducedBandsBandPowerModel("Sound Power Model 4", 4, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel4 = RainbowColorModel("Color Model 4", 4, 8);
    GravitationalModel m_GravitationalModel4 = GravitationalModel("GravitationalModel2", 1.0, 10.0);
    
    VerticalBarView m_VerticalBar5 = VerticalBarView("Vertical Bar 5", 2, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite5 = ColorSpriteView("PeakSprite5", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower5 = ReducedBandsBandPowerModel("Sound Power Model 5", 5, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel5 = RainbowColorModel("Color Model 5", 5, 8);
    GravitationalModel m_GravitationalModel5 = GravitationalModel("GravitationalModel5", 1.0, 10.0);
    
    VerticalBarView m_VerticalBar6 = VerticalBarView("Vertical Bar 6", 3, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite6 = ColorSpriteView("PeakSprite6", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower6 = ReducedBandsBandPowerModel("Sound Power Model 6", 6, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel6 = RainbowColorModel("Color Model 6", 6, 8);
    GravitationalModel m_GravitationalModel6 = GravitationalModel("GravitationalModel6", 1.0, 10.0);
    
    VerticalBarView m_VerticalBar7 = VerticalBarView("Vertical Bar 7", 3, 0, 1, SCREEN_HEIGHT/3, MergeType_Add);
    ColorSpriteView m_PeakSprite7 = ColorSpriteView("PeakSprite7", 0, 0, SCREEN_WIDTH, 2, MergeType_Add);
    ReducedBandsBandPowerModel m_BandPower7 = ReducedBandsBandPowerModel("Sound Power Model 7", 7, 5, 8, m_StatisticalEngineModelInterface);
    RainbowColorModel m_ColorModel7 = RainbowColorModel("Color Model 7", 7, 8);
    GravitationalModel m_GravitationalModel7 = GravitationalModel("GravitationalModel7", 1.0, 10.0);
};
#endif
