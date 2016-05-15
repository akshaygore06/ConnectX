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
TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, emtyInBound)
{
  ConnectX contest;
	ASSERT_EQ(0,contest.at(4,5));
//	contest.showBoard();
}

TEST(ConnectXTest, emptyOutBound)
{
  ConnectX contest;
	ASSERT_EQ(-1,contest.at(8,12));
	//contest.showBoard();
}

TEST(ConnectXTest, toogleTurnBlack)
{
  ConnectX contest;
	ASSERT_EQ(2,contest.whoseTurn());
//	contest.showBoard();
}

TEST(ConnectXTest, toogleTurnWhite)
{
  ConnectX contest;
	contest.placePiece(4);
	ASSERT_EQ(1,contest.whoseTurn());
	contest.showBoard();
}

TEST(ConnectXTest, placePieceInboundBlack)
{
  ConnectX contest;
	contest.placePiece(3);
	contest.showBoard();
	ASSERT_EQ(2,contest.at(3,5));

}

TEST(ConnectXTest, placePieceInboundWhite)
{
  ConnectX contest;
	contest.placePiece(3);
	contest.placePiece(3);
	contest.showBoard();
	ASSERT_EQ(1,contest.at(3,4));
}

TEST(ConnectXTest, placePieceOutboundWidth)
{
  ConnectX contest;
	contest.placePiece(10);
	contest.showBoard();
	ASSERT_EQ(-1,contest.at(10,5));
}

TEST(ConnectXTest, placePieceOutboundHightZero)
{
  ConnectX contest;
	contest.placePiece(5);
	contest.showBoard();
	ASSERT_EQ(-1,contest.at(5,-1));
}


TEST(ConnectXTest, placePieceOutboundHightGreater)
{
  ConnectX contest;
	contest.placePiece(-5);
	contest.showBoard();
	ASSERT_EQ(-1,contest.at(-5,2));
}


TEST(ConnectXTest, placePieceOutboundWidhthLessThanZero)
{
  ConnectX contest;
	contest.placePiece(-5);
	contest.showBoard();
	ASSERT_EQ(-1,contest.at(-5,5));
}

//
// TEST(ConnectXTest, placePieceOutboundHightZero)
// {
//   ConnectX contest;
// 	contest.placePiece(5);
// 	contest.showBoard();
// 	ASSERT_EQ(-1,contest.at(5,-1));
// }

TEST(ConnectXTest, checkConstuctor)
{
  ConnectX contest(8,10,3);
	contest.placePiece(7);
	ASSERT_EQ(0,contest.at(7,3));
	contest.showBoard();
}

TEST(ConnectXTest, checkWinningCondition)
{
  ConnectX contest(4,4,5);
	contest.placePiece(3);
	contest.placePiece(1);
	contest.placePiece(3);
	contest.placePiece(1);
	contest.placePiece(3);
	contest.showBoard();
	ASSERT_EQ(2,contest.at(3,3));

}

TEST(ConnectXTest, checkNegParameter1)
{
  ConnectX contest(-4,4,5);
	contest.placePiece(3);
	contest.showBoard();
	ASSERT_EQ(0,contest.at(3,3));

}

TEST(ConnectXTest, checkNegParameter2)
{
  ConnectX contest(4,-4,5);
	contest.placePiece(3);
	contest.showBoard();
	ASSERT_EQ(0,contest.at(3,3));

}


TEST(ConnectXTest, checkNegParameter3)
{
  ConnectX contest(4,4,-3);
	contest.placePiece(3);
	contest.showBoard();
	ASSERT_EQ(2,contest.at(3,5));

}
