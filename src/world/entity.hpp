#ifndef C4DA406E_30F3_482A_9FE3_4E15D08D1ABE
#define C4DA406E_30F3_482A_9FE3_4E15D08D1ABE

class Entity {
    private:
        bool destroyable;
        int hp;
    public:
        Entity(bool destroyable, int hp);
        virtual ~Entity();
        virtual void render();
        virtual void updateState();
        bool isDestroyable() { return destroyable;}
        int getHealthPoints() {return hp;}
};

#endif /* C4DA406E_30F3_482A_9FE3_4E15D08D1ABE */
