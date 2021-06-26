-- MySQL dump 10.18  Distrib 10.3.27-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: smarthome
-- ------------------------------------------------------
-- Server version	10.3.27-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `light_table`
--

DROP TABLE IF EXISTS `light_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `light_table` (
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(60) NOT NULL,
  `status` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `light_table`
--

LOCK TABLES `light_table` WRITE;
/*!40000 ALTER TABLE `light_table` DISABLE KEYS */;
INSERT INTO `light_table` VALUES (1,'客厅灯',0),(2,'厨房灯',0),(3,'卧室灯',0),(4,'卫生间灯',0);
/*!40000 ALTER TABLE `light_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sensor_table`
--

DROP TABLE IF EXISTS `sensor_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sensor_table` (
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(60) NOT NULL,
  `data` double NOT NULL,
  `locat` varchar(60) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sensor_table`
--

LOCK TABLES `sensor_table` WRITE;
/*!40000 ALTER TABLE `sensor_table` DISABLE KEYS */;
INSERT INTO `sensor_table` VALUES (1,'人体传感',0,'卧室'),(2,'烟雾传感',0,'卧室'),(3,'温度传感',0,'卧室'),(4,'漏水传感',0,'卧室'),(5,'声音传感',0,'卧室'),(6,'人体传感',0,'卫生间'),(7,'烟雾传感',0,'卫生间'),(8,'温度传感',0,'卫生间'),(9,'声音传感',0,'卫生间'),(10,'光照传感',0,'客厅'),(11,'人体传感',0,'客厅'),(12,'烟雾传感',0,'客厅'),(13,'温度传感',0,'客厅'),(14,'漏水传感',0,'客厅'),(15,'人体传感',0,'厨房'),(16,'烟雾传感',0,'厨房'),(17,'温度传感',0,'厨房'),(18,'漏水传感',0,'厨房');
/*!40000 ALTER TABLE `sensor_table` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-05-07 11:52:38
