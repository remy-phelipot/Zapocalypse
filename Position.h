#ifndef POSITION_H
#define POSITION_H

#define POSITION_UNDEFINED -1

class Position {
    public:
        /** Default constructor */
        Position();
        /** Access posX
         * \return The current value of posX
         */
         /** Parameterized constructor */
        Position( int, int );

        int GetposX() { return posX; }
        /** Set posX
         * \param val New value to set
         */
        void SetposX(int val) { posX = val; }
        /** Access posY
         * \return The current value of posY
         */
        int GetposY() { return posY; }
        /** Set posY
         * \param val New value to set
         */
        void SetposY(int val) { posY = val; }

    private:
        int posX; //!< Member variable "posX"
        int posY; //!< Member variable "posY"
};

#endif // POSITION_H
