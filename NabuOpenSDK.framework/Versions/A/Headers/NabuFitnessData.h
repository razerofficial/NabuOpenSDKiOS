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
        @param  startTime       Start time of list of fitness data in Unix timestamp (Epoch Time)
        @param  endTime         End time of list of fitness data in Unix timestamp (Epoch Time)
        @param  fitnessData     List of fitness data
        @param  fitnessHistoryData  List of historical fitness data
 */

@interface NabuFitness : NSObject

@property (copy, nonatomic) NSMutableArray *fitnessData;
@property (copy, nonatomic) NSMutableArray *fitnessHistoryData;

@end

/*!
 @class NabuFitnessData
 @abstract  A class that defines Nabu Fitness Data
    @discussion
        @param bandId      Nabu Device ID
        @param modelName   Nabu Device Type
        @param recordTime  Timestamp of fitness data (start date of data)
        @param calories        Calories spent on fitness activity
        @param distanceWalked  Distance walked on fitness activity
        @param floorClimbed    Floor climbed on fitness activity
        @param steps           Steps taken on fitness activity
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
 @abstract  A class that defines Nabu Fitness History Data
    @discussion
        @param bandId      Nabu Device ID
        @param modelName   Nabu Device Type
        @param recordTime  Timestamp of fitness data (start date of data)
        @param calories        Calories spent on fitness activity
        @param distanceWalked  Distance walked on fitness activity
        @param floorClimbed    Floor climbed on fitness activity
        @param steps           Steps taken on fitness activity
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

