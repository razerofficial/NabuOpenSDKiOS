//
//  NabuUserProfile.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/3/14.
//  Copyright (c) 2014 Razer. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuUserProfile
 @abstract  A class that defines the Nabu user profile
 @discussion
    nickName    - user nickname
    avatar      - user avatar image
    birthDay    - user birth day
    birthMonth  - user birth month
    birthYear   - user birth year
    gender      - user gender
    height      - user height
    weight      - user weight
    unit        - user unit of measurement for height and weight
 @updated 2014-03-11
 */

@interface NabuUserProfile : NSObject


@property (copy, nonatomic) NSString *nickName;
@property (copy, nonatomic) NSString *avatar;
@property (copy, nonatomic) NSString *birthDay;
@property (copy, nonatomic) NSString *birthMonth;
@property (copy, nonatomic) NSString *birthYear;
@property (copy, nonatomic) NSString *gender;
@property (copy, nonatomic) NSString *height;
@property (copy, nonatomic) NSString *weight;
@property (copy, nonatomic) NSString *unit;

@end
