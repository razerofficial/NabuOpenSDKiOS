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

@protocol NabuBandDelegate <NSObject>
@optional
- (void)didConnectToBand:(NabuBand *)band;

- (void)handleLiveFitnessData:(NabuLiveFitness *)fitnessData;
- (void)handleIntervalFitnessData:(NabuIntervalFitness *)intervalFitnessData;
- (void)handleLiveSleepData:(NabuLiveSleep *)sleepData;
@end

@interface NabuBand : NSObject

@property (readonly) NSString *name;
@property (readonly) NSString *uuid;

@property (nonatomic, copy) NSString *bandId;
@property (nonatomic, copy) NSString *model;

@property (readonly, getter = isConnected) BOOL connected;

@property id<NabuBandDelegate> delegate;

- (void)connect;

- (void)setFitnessEnabled:(BOOL)enabled;

- (void)getLastConnectionTimestampWithBlock:(void (^)(NSData *data))block;

- (void)setGoalSteps:(uint32_t)steps distance:(uint32_t)distance calories:(uint32_t)calories sleep:(uint32_t)sleep;

@end
