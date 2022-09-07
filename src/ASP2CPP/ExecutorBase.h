
class ExecutorBase{
    public:
        virtual void init(){};
        virtual void insertFactIntoFactory(const Literal& , bool ){};
        virtual void executeProgram(){};
        virtual ~ExecutorBase(){};
};