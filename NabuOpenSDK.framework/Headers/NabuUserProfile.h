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
 @abstract  A class that defines a Nabu User Profile
    @discussion
        @param  nickName    User's nickname
        @param  avatar      User's avatar image
        @param  birthDay    User's birth day
        @param  birthMonth  User's birth month
        @param  birthYear   User's birth year
        @param  gender      User's gender
        @param  height      User's height
        @param  weight      User's weight
        @param  unit        Unit of measurement for user's height and weight
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
