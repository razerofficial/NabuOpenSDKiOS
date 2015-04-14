//
//  NabuBandManager.h
//  RazerSynapseSDK
//
//  Created by Razer on 28/11/14.
//  Copyright (c) 2014 Razer Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuBandManager
 @abstract  A class that defines the Nabu Band Manager. The Nabu Band Manager is the core object that interacts and manages the Nabu band devices.
    @discussion
 
        @param  availableBands   Array of Available Nabu Bands
 */

@interface NabuBandManager : NSObject

@property (nonatomic, readonly) NSArray *availableBands;


/**
 *  Singleton object for Nabu Band Manager
 *
 */
+ (NabuBandManager *)sharedInstance;


/**
 *  Refresh the current list of available bands.
 *
 */
- (void)refreshAvailableBands;

/**
 *  Refresh status for a subset of available bands with an array of given band identifiers.
 *
 */
- (void)refreshAvailableBandsWithIdentifiers:(NSArray *)identifiers;

@end
