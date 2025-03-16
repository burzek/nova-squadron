#ifndef DC4D1F4A_888D_4389_919B_CC582CDAEEAA
#define DC4D1F4A_888D_4389_919B_CC582CDAEEAA

class Enemy : Entity {
    private:
    public:
        Enemy();
        virtual ~Enemy();
                
        virtual void render(const SDLContext& sdlContext) = 0;
        virtual void updateState() = 0;
        virtual EntityType getType() = 0;
        virtual int getInitialHealthPoints() = 0;

        bool isRenderable() {return true;};
        bool isDestroyable() {return true;};

};

#endif /* DC4D1F4A_888D_4389_919B_CC582CDAEEAA */
