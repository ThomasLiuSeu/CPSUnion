DROP DATABASE CPSUnion;
CREATE DATABASE CPSUnion;
use CPSUnion;

CREATE TABLE IF NOT EXISTS `user` (
`user_id` BIGINT( 11 ) NOT NULL,
`user_name` VARCHAR( 1023 ) NOT NULL,
`account` VARCHAR( 1023 ) ,
`password` VARCHAR( 1023 ) NOT NULL,
`token` VARCHAR( 1023 ) NOT NULL,
`store_enable` BLOB(1023) NOT  NULL,
 PRIMARY KEY(`user_id`),
 ) ENGINE=InnoDB  DEFAULT CHARSET=utf8 

CREATE TABLE IF NOT EXISTS `union` (
`union_id` BIGINT( 11 ) NOT NULL,
`union_name` VARCHAR( 1023 ) NOT NULL,
 ) ENGINE=InnoDB  DEFAULT CHARSET=utf8 

CREATE TABLE IF NOT EXISTS `campaign` (
`campaign_id` BIGINT( 11 ) NOT NULL,
`campaign_name` VARCHAR( 1023 ) NOT NULL,
`pattern` VARCHAR( 1023 ) NOT NULL,
`union_id` BIGINT( 11 ) NOT NULL,
`outer_campaign_id` BIGINT( 11 ) ,
 PRIMARY KEY(`campaign_id`),
 FOREIGN KEY (`union_id`)  REFERENCES `union`(`union_id`)
 ) ENGINE=InnoDB  DEFAULT CHARSET=utf

CREATE TABLE IF NOT EXISTS `clicks` (
`click_id` BIGINT( 11 ) NOT NULL AUTO_INCREMENT ,
`user_id` BIGINT( 11 ) NOT NULL,
`campaign_id` BIGINT( 11 ) NOT NULL,
`click_time` BIGINT( 11 ) NOT NULL,
`tags` VARCHAR(1023) ,
 PRIMARY KEY(`click_id`),
 FOREIGN KEY (`user_id`)  REFERENCES `user`(`user_id`),
 FOREIGN KEY (`campaign_id`)  REFERENCES `campaign`(`campaign_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 ;

CREATE TABLE IF NOT EXISTS `orders` (
`order_id` BIGINT( 11 ) NOT NULL  ,
`click_id` BIGINT( 11 ) NOT NULL AUTO_INCREMENT ,
`union_id` BIGINT( 11 ) NOT NULL,
`store_id` BIGINT( 11 ) NOT NULL,
`store_name` VARCHAR(1023)  DEFAULT "",
`trading_volume` BIGINT( 11 ) ,
`cashback` BIGINT( 11 ) NOT NULL,
`order_time` BIGINT( 11 ) ,
`report_time` BIGINT( 11 ),
`valid_time` BIGINT( 11 ),
`currency_type` VARCHAR(1023)  DEFAULT NULL,
`status` BIGINT( 11 ) NOT NULL,
 PRIMARY KEY(`order_id`),
 FOREIGN KEY (`click_id`)  REFERENCES `clicks`(`click_id`)
 ) ENGINE=InnoDB  DEFAULT CHARSET=utf8 

