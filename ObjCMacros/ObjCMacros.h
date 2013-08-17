//
//  ObjCMacros.h
//
//  Created by Constantine Mureev and Artem Samalov on 18.07.13.
//  Copyright (c) 2013 Team Force LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*
 *  Geometry
 */

#define DEG_TO_RAD(degrees) ((degrees) * M_PI / 180.0)
#define RAD_TO_DEG(radians) ((radians) * 180.0 / M_PI)

/*
 *  Strings
 */

#define	NSLS(str)   NSLocalizedString(str, nil)

#define IS_EMPTY_STRING(str)            (!(str) || ![(str) isKindOfClass:NSString.class] || [(str) length] == 0)
#define IS_POPULATED_STRING(str)        ((str) && [(str) isKindOfClass:NSString.class] && [(str) length] > 0)

/*
 *  Arrays
 */

#define IS_EMPTY_ARRAY(arr)             (!(arr) || ![(arr) isKindOfClass:NSArray.class] || [(arr) count] == 0)
#define IS_POPULATED_ARRAY(arr)         ((arr) && [(arr) isKindOfClass:NSArray.class] && [(arr) count] > 0)

/*
 *  Dictionaries
 */

#define IS_EMPTY_DICTIONARY(dic)        (!(dic) || ![(dic) isKindOfClass:NSDictionary.class] || [(dic) count] == 0)
#define IS_POPULATED_DICTIONARY(dic)    ((dic) && [(dic) isKindOfClass:NSDictionary.class] && [(dic) count] > 0)

/*
 *  Colors
 */

#define RGB(col) ((col) / 255.0f)

/*
 *  Hardware / Device info
 */

#define UI_IPAD         ( [ UIDevice currentDevice ].userInterfaceIdiom == UIUserInterfaceIdiomPad )
#define UI_IPHONE       ( [ UIDevice currentDevice ].userInterfaceIdiom == UIUserInterfaceIdiomPhone )
#define UI_WIDESCREEN   ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )

#define IS_IPHONE       ( [ [ [ UIDevice currentDevice ] model ] isEqualToString: @"iPhone" ] )
#define IS_IPOD         ( [ [ [ UIDevice currentDevice ] model ] isEqualToString: @"iPod touch" ] )
#define IS_IPAD         ( [ [ [ UIDevice currentDevice ] model ] isEqualToString: @"iPad" ] )

#define CAN_CALL        ( [[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"tel://"]] )

/*
 *  Screen / Display
 */

#define IS_DEVICE_ORIENTATION_PORTRAIT(orientation)     ((orientation) == UIDeviceOrientationPortrait || (orientation) == UIDeviceOrientationPortraitUpsideDown)
#define IS_DEVICE_ORIENTATION_LANDSCAPE(orientation)    ((orientation) == UIDeviceOrientationLandscapeLeft || (orientation) == UIDeviceOrientationLandscapeRight)

#define IS_DEVICE_ORIENTATION_FACE_UP                   ([UIDevice currentDevice].orientation == UIDeviceOrientationFaceUp)
#define IS_DEVICE_ORIENTATION_FACE_DOWN                 ([UIDevice currentDevice].orientation == UIDeviceOrientationFaceDown)

#define HARDWARE_SCREEN_WIDTH                           ([UIScreen mainScreen].bounds.size.width)
#define HARDWARE_SCREEN_HEIGHT                          ([UIScreen mainScreen].bounds.size.height)

/*
 *  System Versioning
 */


#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

/*
 *  Exceptions
 */

#define kArgumentException @"ArgumentException"
#define kArgumentNilException @"ArgumentNilException"
#define kArgumentNilOrEmptyException @"ArgumentNilOrEmptyException"
#define kNilObjectException @"NilObjectException"
#define kInvalidOperationException @"InvalidOperationException"
#define kInvalidObjectTypeException @"InvalidObjectTypeException"
#define kNotImplementedException @"NotImplementedException"
#define kOutOfRangeException @"OutOfRangeException"

#define AssertIndexInRange(parameter, parameterName, min, max) if (parameter < min || parameter > max) { \
@throw [NSException exceptionWithName:kOutOfRangeException \
reason:[NSString stringWithFormat:@"%s, %d -> the parameter '%@' with value %d is out of bounds [%d .. %d].", __FUNCTION__, __LINE__, parameterName, parameter, min, max] \
userInfo:nil]; }

#define AssertIndexLessThan(parameter, parameterName, max) if (parameter >= max) { \
@throw [NSException exceptionWithName:kOutOfRangeException \
reason:[NSString stringWithFormat:@"%s, %d -> the parameter '%@' with upper bound %d has the value %d.", __FUNCTION__, __LINE__, parameterName,max, parameter] \
userInfo:nil]; }

#define AssertArgumentNotNil(argument, argumentName) if (argument == nil) { \
@throw [NSException exceptionWithName:kArgumentNilException \
reason:[NSString stringWithFormat:@"%s, %d -> the parameter %@ can not be nil.", __FUNCTION__, __LINE__, argumentName] \
userInfo:nil]; }

#define AssertArgumentNotNilOrEmptyString(argument, argumentName) if (!IS_POPULATED_STRING(argument)) { \
@throw [NSException exceptionWithName:kArgumentNilOrEmptyException \
reason:[NSString stringWithFormat:@"%s, %d -> the parameter %@ can not be nil or empty.", __FUNCTION__, __LINE__, argumentName] \
userInfo:nil]; }

#define AssertObjectNotNil(var, varName) if (var == nil) { \
@throw [NSException exceptionWithName:kNilObjectException \
reason:[NSString stringWithFormat:@"%s, %d -> the variable %@ should not be nil.", __FUNCTION__, __LINE__, varName] \
userInfo:nil]; }

#define AssertStringNonEmptyOrNil(string, argumentName) if (!IS_POPULATED_STRING(argument)) { \
@throw [NSException exceptionWithName:kArgumentException \
reason:[NSString stringWithFormat:@"%s, %d -> the parameter %@ can not be empty or nil.", __FUNCTION__, __LINE__, argumentName] \
userInfo:nil]; }

#define AssertObjectConformsProtocol(obj, objName, protocol) if (![obj conformsToProtocol:protocol]) { \
@throw [NSException exceptionWithName:kInvalidOperationException \
reason:[NSString stringWithFormat:@"%s, %d -> object %@ should conforms to the protocol %@.", __FUNCTION__, __LINE__, objName, protocol] \
userInfo:nil]; }

#define AssertObjectIsKindOfClass(obj, objName, requiredType) if (![obj isKindOfClass:[requiredType class]]) { \
@throw [NSException exceptionWithName:kInvalidObjectTypeException \
reason:[NSString stringWithFormat:@"%s, %d -> object %@ should be of type %@. Real type is %@", __FUNCTION__, __LINE__, objName, [[requiredType class] description], [[obj class] description]] \
userInfo:nil]; }

#define THROW_NOT_IMPLEMENTED_EXCEPTION @throw [NSException exceptionWithName:kNotImplementedException reason:[NSString stringWithFormat:@"%s -> the method is not implemented.", __FUNCTION__] userInfo:nil];