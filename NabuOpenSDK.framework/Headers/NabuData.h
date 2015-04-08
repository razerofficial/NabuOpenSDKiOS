//
//  NabuData.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/12/14.
//  Copyright (c) 2014 Razer Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NabuLiveFitnessData : NSObject

@property (nonatomic) uint32_t steps;
@property (nonatomic) uint32_t distance;
@property (nonatomic) uint32_t calories;
@property (nonatomic) uint32_t activeMinutes;

@end

@interface NabuLiveFitness : NSObject

@property (nonatomic) NSString *bandName;
@property (nonatomic) NabuLiveFitnessData *totalFitness;

@end


@interface NabuIntervalFitnessData : NSObject

@property (nonatomic) NSInteger timestamp;
@property (nonatomic) uint16_t steps;
@property (nonatomic) uint16_t distance;
@property (nonatomic) uint16_t calories;
@property (nonatomic) uint16_t floors;

@end

@interface NabuIntervalFitness : NSObject

@property (nonatomic) NSString *bandName;
@property (nonatomic) NabuIntervalFitnessData *intervalFitness;

@end


@interface NabuLiveSleepData : NSObject

@property (nonatomic) NSInteger startTimestamp;
@property (nonatomic) NSInteger endTimestamp;

@property (nonatomic) NSData *sleepData;

@end

@interface NabuLiveSleep : NSObject

@property (nonatomic) NSString *bandName;
@property (nonatomic) NabuLiveSleepData *sleep;

@end