//
//  NabuBandData.h
//  RazerSynapseSDK
//
//  Created by Razer on 8/12/14.
//  Copyright (c) 2014 Razer. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuBandData
 @abstract  A class that defines a Nabu Band
    @discussion
        @param name            Device Name
        @param model           Model of Nabu Device
        @param bandId          ID of the Nabu Band
        @param serialNumber    Serial Number of the Nabu Band
 */

@interface NabuBandData : NSObject

@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *model;
@property (copy, nonatomic) NSString *bandId;
@property (copy, nonatomic) NSString *serialNumber;

@end
