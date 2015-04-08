//
//  NabuClipboardObject.h
//  RazerSynapseSDK
//
//  Created by Razer on 4/7/15.
//  Copyright (c) 2015 Razer Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NabuClipboardObject : NSObject

/*! Public Data saved in the clipboard. Can be accessed by anyone with the users OpenID.
 *
 *  Limited to 2k in size
 */
@property (nonatomic, strong) NSData *publicData;

/*! Private Data saved in the clipboard. Can only be accessed by the current user.
 *
 *  Limited to 2k in size
 */
@property (nonatomic, strong) NSData *privateData;

/*! Commit Message saved in the clipboard. Can be accessed by anyone with the users OpenID.
 *
 *  Limited to 140 Characters
 */
@property (nonatomic, strong) NSString *message;

/*! OpenID of user who the clipboard belongs to.
 */
@property (nonatomic, strong) NSString *openID;

@end
