#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include <stdlib.h>
#include <vector>

class Board;

using namespace std;

enum Colour
{
    White,
    Black
};

enum PieceType
{
    ROOK,
    PAWN,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

enum MoveType
{
    STANDARD,
    CAPTURING,
    CASTLING,
    ENPASSANT,
    CHECKING
};

struct Move
{
    int x, y;
    MoveType type;
};

class ChessPiece
{
protected:
    Colour mycolour;
    vector<Move> validMoves; // change this to protected

public:
    ChessPiece(Colour c);
    bool isLegalMove(int newx, int newy, Colour turn);
    vector<Move> *getValidMoves();
    void deleteMove(int newx, int newy);
    virtual void refreshLegalMoves(int x, int y, Board &b) = 0;
    Colour getColour();
    virtual PieceType getType() = 0;
    virtual char getPieceChar() = 0;
    virtual int getValue() = 0;
    virtual ~ChessPiece();
};

class Pawn : public ChessPiece
{
    bool justMovedTwo = false;

public:
    Pawn(Colour c);
    void setMovedTwo(bool b);
    bool getMovedTwo();
    PieceType getType() override;
    void refreshLegalMoves(int x, int y, Board &b) override;
    int getValue() override;
    char getPieceChar() override;
};

class Rook : public ChessPiece
{
    bool moved;

public:
    Rook(Colour c);
    void setMoved(bool b);
    bool getMoved();
    PieceType getType() override;
    int getValue() override;
    void refreshLegalMoves(int x, int y, Board &b) override;
    char getPieceChar() override;
};

class Bishop : public ChessPiece
{
public:
    Bishop(Colour c);
    PieceType getType() override;
    int getValue() override;
    void refreshLegalMoves(int x, int y, Board &b) override;
    char getPieceChar() override;
};

class King : public ChessPiece
{
    bool moved;

public:
    King(Colour c);
    PieceType getType() override;
    void setMoved(bool b);
    int getValue() override;
    bool getMoved();
    void refreshLegalMoves(int x, int y, Board &b) override;
    char getPieceChar() override;
};

class Queen : public ChessPiece
{
public:
    Queen(Colour c);
    PieceType getType() override;
    int getValue() override;
    void refreshLegalMoves(int x, int y, Board &b) override;
    char getPieceChar() override;
};

class Knight : public ChessPiece
{
public:
    Knight(Colour c);
    PieceType getType() override;
    int getValue() override;
    void refreshLegalMoves(int x, int y, Board &b) override;
    char getPieceChar() override;
};
#endif