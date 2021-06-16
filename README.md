# libpigmentation
** libpigmentation offers the ability to obtain colors from an image. **

## Repo: [https://nahtedetihw.github.io](https://nahtedetihw.github.io)

# Usage

## Installation in Theos

### Installation

1. Download this repository
2. Put the `.dylib` into your `theos/lib` folder
3. Put the `libpigmentation.h` file into your `theos/include` folder

## Configuration
1. Add `TWEAKNAME_LIBRARIES = pigmentation` to your makefile
2. Add `com.nahtedetihw.libpigmentation` to the `Depends` in your `control` file

```objc
@interface libpigmentation : NSObject
-(NSDictionary *)coloursForImage:(UIImage *)image forEdge:(int)edge;
- (BOOL)isColorTooDark:(UIColor *)color;
- (BOOL)isColorTooLight:(UIColor *)color;
- (UIColor *)lighterColorForColor:(UIColor *)color;
- (UIColor *)darkerColorForColor:(UIColor *)color;
@end

// begin example
%hook YOURMETHOD
- (void)viewDidLoad {
    %orig;
    // create an instance of our pigment library
    libpigmentation *pigment = [[libpigmentation alloc] init];
    
    // grab our original color
    UIColor *origColor = [[pigment coloursForImage:YOURIMAGE forEdge:1] objectForKey:@"primary"];
    
    // determine if the color is too dark
    if ([pigment isColorTooDark:origColor]) {
        
        // return a lighter color of the original color
        UIColor *newDarkColor = [pigment lighterColorForColor:origColor];
        
        // apply our new lighter color to the object we want
        YOURLABEL.textColor = newDarkColor;
        
    // determine if the color is too light
    } else if ([pigment isColorTooLight:origColor]) {
        
        // return a darker color of the original color
        UIColor *newLightColor = [pigment darkerColorForColor:origColor];
        
        // apply our darker color to the object we want
        nowPlayingInfoSong.textColor = newLightColor;
        
    // if our color is not too dark and not too light we use original color
    } else {
    
        // apply our original color to the object we want
        nowPlayingInfoSong.textColor = origColor;
    }
}
%end
// end example

// types of colors
[[pigment coloursForImage:YOURIMAGE forEdge:1] objectForKey:@"primary"]; // most common
[[pigment coloursForImage:YOURIMAGE forEdge:1] objectForKey:@"secondary"]; // most contrasting
[[pigment coloursForImage:YOURIMAGE forEdge:1] objectForKey:@"background"]; // edge color

// finding the right edge
0 = top
1 = left
2 = bottom
3 = right

```
