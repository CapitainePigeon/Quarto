#ifndef PIECE_H
#define PIECE_H


class piece
{
    public: //constructeurs
        piece();
        piece (couleur, taille, forme, pleine);
        virtual ~piece();

    protected:

    private:
        bool couleur;
        bool taille;
        bool forme;
        bool pleine;
};

#endif // PIECE_H
