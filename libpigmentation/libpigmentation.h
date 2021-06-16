@interface libpigmentation : NSObject
-(NSDictionary *)coloursForImage:(UIImage *)image forEdge:(int)edge;
- (BOOL)isColorTooDark:(UIColor *)color;
- (BOOL)isColorTooLight:(UIColor *)color;
- (UIColor *)lighterColorForColor:(UIColor *)color;
- (UIColor *)darkerColorForColor:(UIColor *)color;
@end
