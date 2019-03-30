#ifndef PIECE_H
#define PIECE_H


class Piece
{
public: //constructeurs
    Piece();

    Piece(bool couleur, bool taille,bool forme, bool pleine);
    virtual ~Piece();
    void pieceCaractere();
    char getCaractere();
    bool couleur;
    bool taille;
    bool forme;
    bool pleine;


private:

    char caractere;
};

#endif // PIECE_H
