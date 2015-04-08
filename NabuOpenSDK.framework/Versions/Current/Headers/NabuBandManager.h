//
//  NabuBandManager.h
//  RazerSynapseSDK
//
//  Created by Razer on 28/11/14.
//  Copyright (c) 2014 Razer Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NabuBandManager : NSObject

@property (nonatomic, readonly) NSArray *availableBands;

+ (NabuBandManager *)sharedInstance;

- (void)refreshAvailableBands;
- (void)refreshAvailableBandsWithIdentifiers:(NSArray *)identifiers;

@end
