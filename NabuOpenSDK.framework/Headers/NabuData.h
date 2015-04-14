//
//  NabuData.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/12/14.
//  Copyright (c) 2014 Razer Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuLiveFitnessData
 @abstract  A class that defines Live Nabu Fitness Data (Directly from the Nabu Band).
    @discussion
        @param steps           Steps taken
        @param distance        Distance walked
        @param calories        Number of calories burned
        @param activeMinutes   Number of minutes of activity
 */

@interface NabuLiveFitnessData : NSObject

@property (nonatomic) uint32_t steps;
@property (nonatomic) uint32_t distance;
@property (nonatomic) uint32_t calories;
@property (nonatomic) uint32_t activeMinutes;

@end

/*!
 @class NabuLiveFitness Object
 @abstract  A class that defines Live Nabu Fitness Object.
    @discussion
        @param bandName           Band Name
        @param totalFitness       Nabu Live Fitness Data Object
 */


@interface NabuLiveFitness : NSObject

@property (nonatomic) NSString *bandName;
@property (nonatomic) NabuLiveFitnessData *totalFitness;

@end

/*!
 @class NabuIntervalFitness
 @abstract  A class that defines Nabu Interval Fitness Data.
    @discussion
        @param steps           Steps taken
        @param distance        Distance walked
        @param calories        Number of calories burned
        @param activeMinutes   Number of minutes of activity
 */

@interface NabuIntervalFitnessData : NSObject

@property (nonatomic) NSInteger timestamp;
@property (nonatomic) uint16_t steps;
@property (nonatomic) uint16_t distance;
@property (nonatomic) uint16_t calories;
@property (nonatomic) uint16_t floors;

@end

/*!
 @class NabuIntervalFitness Object
 @abstract  A class that defines Nabu Interval Fitness Object.
    @discussion
        @param bandName           Band Name
        @param intervalFitness    Nabu Interval Fitness Data Object
 */

@interface NabuIntervalFitness : NSObject

@property (nonatomic) NSString *bandName;
@property (nonatomic) NabuIntervalFitnessData *intervalFitness;

@end


/*!
 @class NabuLiveSleepData
 @abstract  A class that defines Nabu Live Sleep Data.
    @discussion
        @param startTimestamp   Start time of sleep data.
        @param endTimestamp     End time of sleep data.
        @param sleepData        Raw Sleep Data.
 */

@interface NabuLiveSleepData : NSObject

@property (nonatomic) NSInteger startTimestamp;
@property (nonatomic) NSInteger endTimestamp;

@property (nonatomic) NSData *sleepData;

@end

/*!
 @class NabuLiveSleep
 @abstract  A class that defines Nabu Live Sleep Object.
    @discussion
        @param bandName     Band Name
        @param sleep        Nabu Live Sleep Data Object
 */

@interface NabuLiveSleep : NSObject

@property (nonatomic) NSString *bandName;
@property (nonatomic) NabuLiveSleepData *sleep;

@end