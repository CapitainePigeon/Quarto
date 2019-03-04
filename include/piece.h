#ifndef PIECE_H
#define PIECE_H


class piece
{
public: //constructeurs
    piece();

    piece(bool couleur, bool taille,bool forme, bool pleine);
    virtual ~piece();
    void pieceCaractere();
    char getCaractere();


private:
    bool couleur;
    bool taille;
    bool forme;
    bool pleine;
    char caractere;
};

#endif // PIECE_H
