//
//  NabuBand.h
//  RazerSynapseSDK
//
//  Created by Razer on 28/11/14.
//  Copyright (c) 2014 Razer Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NabuData.h"

@class NabuBand;

/*!
 @class Nabu Band Delegate Protocol
 @abstract A class that defines the protocol for status messages being recieved by the Nabu Band.
 @discussion
 */
@protocol NabuBandDelegate <NSObject>
@optional
- (void)didConnectToBand:(NabuBand *)band; ///Called when the BTLE connection is established with the band.

- (void)handleLiveFitnessData:(NabuLiveFitness *)fitnessData; ///Called when the band sends live fitness data.
- (void)handleIntervalFitnessData:(NabuIntervalFitness *)intervalFitnessData; ///Called when the bands ends interval fitness data.
- (void)handleLiveSleepData:(NabuLiveSleep *)sleepData; ///Called when teh band sends live sleep data for the user to manage.
@end


/*!
 @class NabuBand
 @abstract A class that defines the data for a Nabu Band
    @discussion
 
        @param  name   Name of Nabu Band.
        @param  uuid   Get Nabu Band UUID.
        @param  connected   Check status of Nabu Band Connection.
        @param  <NabuBandDelegate>delegate  Nabu Band delegate object.
 */
@interface NabuBand : NSObject

@property (readonly) NSString *name;
@property (readonly) NSString *uuid;

@property (nonatomic, copy) NSString *bandId;
@property (nonatomic, copy) NSString *model;

@property (readonly, getter = isConnected) BOOL connected;

@property id<NabuBandDelegate> delegate;

- (void)connect; ///Establish connection with Nabu Band. Connection state is managed via delegate.

- (void)setFitnessEnabled:(BOOL)enabled;  ///Enable or Disable Fitness tracking on Nabu Band.

- (void)getLastConnectionTimestampWithBlock:(void (^)(NSData *data))block;

- (void)setGoalSteps:(uint32_t)steps distance:(uint32_t)distance calories:(uint32_t)calories sleep:(uint32_t)sleep;  ///Set goal for user.

@end
