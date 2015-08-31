create database CPSUnion;
use CPSUnion;
CREATE TABLE `clicks` (
`click_id` BIGINT( 11 ) NOT NULL AUTO_INCREMENT ,
`user_id` BIGINT( 11 ) NOT NULL,
`click_time` BIGINT( 11 ) NOT NULL,
`tags` VARCHAR(1023)  DEFAULT NULL,
 PRIMARY KEY(`click_id`),
 KEY `user_id`(`user_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 