#ifndef PIECE_H
#define PIECE_H


class Piece
{
public: //constructeurs
    Piece();

    Piece(bool couleur, bool taille,bool forme, bool pleine);
    Piece(bool nullaa);
    virtual ~Piece();
    void pieceCaractere();
    char getCaractere();
    bool couleur;
    bool taille;
    bool forme;
    bool pleine;
    bool isnull;
    char caractere;


private:


};

#endif // PIECE_H
