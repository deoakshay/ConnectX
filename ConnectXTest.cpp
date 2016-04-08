/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck) // Display board basic test.
{
	ConnectX conn;
	conn.showBoard();
	ASSERT_TRUE(true);
	
}

TEST(ConnectXTest, turnCheck) // Check if there is proper turn switiching.
{
	ConnectX conn;
	ASSERT_EQ(2,conn.whoseTurn());
	conn.placePiece(3);
	ASSERT_EQ(1,conn.whoseTurn());
	conn.placePiece(2);
	ASSERT_EQ(2,conn.whoseTurn());
}

TEST(ConnectXTest, boardDisplayCheck) //Check if pieces are placed properly.
{
	ConnectX conn1(4,5,3);
	conn1.showBoard();
	conn1.placePiece(3);
	conn1.showBoard();	
	conn1.placePiece(2);
	conn1.showBoard();
}

TEST(ConnectXTest, consCheck) //Check possible condition cases for constructor.
{
	ConnectX conn1(4,5,3);
	ConnectX conn2(-4,5,2);
	ConnectX conn3(4,-5,3);	
	ConnectX conn4(4,5,-3);
}

TEST(ConnectXTest, atCheck) //Checking validity of pieces placed at various locations.
{
	ConnectX conn1(10,10,5);
	ASSERT_EQ(0,conn1.at(7,8));
	conn1.placePiece(7);
	ASSERT_EQ(-1,conn1.at(0,-1));
	conn1.placePiece(5);
	ASSERT_EQ(1,conn1.at(10,5));	

}

TEST(ConnectXTest, placePieceCheck) // Check if piece value in board is updated.
{
	ConnectX conn1(10,10,5);
	conn1.showBoard();
	conn1.placePiece(0);
	ASSERT_EQ(0,conn1.at(0,0));
	conn1.placePiece(5);
	conn1.placePiece(3);
}
	
TEST(ConnectXTest, placePieceCheck2) // Check for height =1  
{
	ConnectX conn1(10,1,5);
	conn1.placePiece(0);
	conn1.placePiece(0);
}	
