//
//  NabuClipboardManager.h
//  RazerSynapseSDK
//
//  Created by Razer on 4/7/15.
//  Copyright (c) 2015 Razer Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NabuClipboardObject.h"

@interface NabuClipboardManager : NSObject

/**
 *  Use this method to write to NSData to your current users clipboard.
 *
 *  The clipboard is a data store that users are able to upload public or private data to.
 *  Useful for communicating between users.
 */
+(void)writePublicData:(NSData *)publicData withPrivateData:(NSData *)privateData toClipboardWithWriteMessage:(NSString *)message withCompletion:(void(^)(BOOL success, NSError *error))completion;


/**
 *  Use this method to write to NSDictionaries to your current users clipboard.
 *
 *  The clipboard is a data store that users are able to upload public or private data to.
 *  Useful for communicating between users.
 */
+(void)writePublicDictionary:(NSDictionary *)publicDic withPrivateDictionary:(NSDictionary *)privateDic toClipboardWithWriteMessage:(NSString *)message withCompletion:(void(^)(BOOL success, NSError *error))completion;





/**
 *  Use this method to delete a users clipboard.
 *
 *  The clipboard is a data store that users are able to upload public or private data to.
 *  Useful for communicating between users.
 */
+(void)deleteClipboardWithCompletion:(void(^)(BOOL success, NSError *error))completion;







/**
 *  Use this method to get the current user's clipboard information.
 *
 *  The clipboard is a data store that users are able to upload public or private data to.
 *  Useful for communicating between users.
 *  \see NabuClipboardObject
 */
+(void)getClipboardForCurrentUserWithCompletion:(void(^)(NabuClipboardObject *clipboard, NSError *error))completion;


/**
 *  Use this method to get a users public clipboard for a given OpenID.
 *
 *  The clipboard is a data store that users are able to upload public or private data to.
 *  Useful for communicating between users.
 *  \see NabuClipboardObject
 */
+(void)getClipboardForUserWithOpenID:(NSString *)openID withCompletion:(void(^)(NabuClipboardObject *clipboard, NSError *error))completion;


/**
 *  Use this method to get an array of NabuClipboardObjects for a given array of OpenID's.
 *
 *  Limited to 20 OpenID's per request.
 * 
 *  The clipboard is a data store that users are able to upload public or private data to.
 *  Useful for communicating between users.
 *  \see NabuClipboardObject
 */
+(void)getClipboardForUsersWithOpenIDs:(NSArray *)arrayOfOpenIDs withCompletion:(void(^)(NSArray *clipboards, NSError *error))completion;

@end
