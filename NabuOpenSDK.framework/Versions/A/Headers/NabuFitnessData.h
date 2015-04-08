//
//  NabuFitnessData.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/3/14.
//  Copyright (c) 2014 Razer. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuFitness
 @abstract A class that defines a list of Nabu fitness data within a specified time
 @discussion
    startTime   - start time of list of fitness data in Unix timestamp
    endTime     - end time of list of fitness data in Unix timestamp
    fitnessData - list of fitness data
 @updated 2014-03-11
 */

@interface NabuFitness : NSObject

@property (copy, nonatomic) NSMutableArray *fitnessData;
@property (copy, nonatomic) NSMutableArray *fitnessHistoryData;

@end

/*!
 @class NabuFitnessData
 @abstract  A class that defines the Nabu Fitness Data
 @discussion
    calories        - calories spent on fitness activity
    distanceWalked  - distance walked on fitness activity
    floorClimbed    - floor climbed on fitness activity
    steps           - steps taken on fitness activity
 @updated 2014-03-11
 */

@interface NabuFitnessData : NSObject

@property (nonatomic) NSString *bandId;
@property (nonatomic) NSString *modelName;

@property (nonatomic) NSInteger recordTime;

@property (nonatomic) NSInteger calories;
@property (nonatomic) NSInteger distanceWalked;
@property (nonatomic) NSInteger floorClimbed;
@property (nonatomic) NSInteger steps;


@end


/*!
 @class NabuFitnessHistoryData
 @abstract  A class that defines the Nabu Fitness History Data
 @discussion
    calories        - calories spent on fitness activity
    distanceWalked  - distance walked on fitness activity
    floorClimbed    - floor climbed on fitness activity
    steps           - steps taken on fitness activity
 @updated 2014-03-11
 */

@interface NabuFitnessHistoryData : NSObject

@property (nonatomic) NSString *bandId;
@property (nonatomic) NSString *modelName;

@property (nonatomic) NSInteger recordDate;

@property (nonatomic) NSInteger calories;
@property (nonatomic) NSInteger distanceWalked;
@property (nonatomic) NSInteger floorClimbed;
@property (nonatomic) NSInteger steps;


@end

