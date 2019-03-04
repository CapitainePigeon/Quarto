#ifndef PIECE_H
#define PIECE_H


class piece
{
    public: //constructeurs
        piece();
        piece(bool couleur,bool taille,bool forme,bool pleine);
        virtual ~piece();
        void pieceCaractere();



    private:
        bool couleur;
        bool taille;
        bool forme;
        bool pleine;
};

#endif // PIECE_H
