# ObjCMacros

[![Badge w/ Version](http://cocoapod-badges.herokuapp.com/v/ObjCMacros/badge.png)](http://cocoadocs.org/docsets/ObjCMacros)
[![Badge w/ Platform](http://cocoapod-badges.herokuapp.com/p/ObjCMacros/badge.png)](http://cocoadocs.org/docsets/ObjCMacros)

ObjCMacros is set of macros and constants that speed up development without adding any new classes and categories.

## Example Usage

### Working with RGB colors

```objective-c
[UIColor colorWithRed:RGB(102) green:RGB(51) blue:RGB(53) alpha:1];
```

### Using NSLocalizedString

```objective-c
NSLS(@"UNIQUE_KEY");
```

### Is populated string?

```objective-c
if (IS_POPULATED_STRING(str)) {
        // statements-if-true
} else {
        // statements-if-false
}
```

### And even more!

ObjCMacros.h contains so many to choose from!

## License

ObjCMacros is available under the MIT license. See the LICENSE file for more info.
