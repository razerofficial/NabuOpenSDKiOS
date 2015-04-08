//
//  NabuNotification.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/3/14.
//  Copyright (c) 2014 Razer. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuNotification
 @abstract  A class that defines s Nabu Notification Object
 @discussion
    iconResId       - icon resource id
    text            - Notification centered text string (use when only one line) (depreciated use message)
    text1           - Notification top text string (use when more than one line) (depreciated use message)
    text2           - Notification bottom text string (use when more than one line) (depreciated use message)
    status          - Notification status (depreciated)
    message         - Notification message text. Display up to 2 lines separated by standard new line deliminator '\n'
 */


@interface NabuNotification : NSObject

@property (copy, nonatomic) NSString *iconResId;
@property (copy, nonatomic) NSString *text DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use message");
@property (copy, nonatomic) NSString *text1 DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use message");
@property (copy, nonatomic) NSString *text2 DEPRECATED_MSG_ATTRIBUTE("Deprecated - Use message");
@property (copy, nonatomic) NSString *status DEPRECATED_MSG_ATTRIBUTE("Deprecated");
@property (copy, nonatomic) NSString *message; ///Notification Message Text - Display up to 2 lines separated by standard new line deliminator '\n'

/*! Create Nabu Notification Object with a given message and icon
 *          -Example:
 *                      [NabuNotification notificationWithMessage:@"Hello World" andIconResID:@"smiley"];
 */
+(NabuNotification *)notificationWithMessage:(NSString *)message andIconResID:(NSString *)iconResID;

@end
