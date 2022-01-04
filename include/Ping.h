#ifndef PING_H
#define PING_H


class Ping
{
    private:
        int prop1;
        int prop2;

    public:
        Ping();
        virtual ~Ping();

        void encode();
        void decode();

};

#endif // PING_H
