class User():
    def __init__(self, name, uuid = None, isLog = False):
        self.name = name
        self.uuid = uuid
        self.isLog = False

    def getName(self):
        return self.name

    def getUuid(self):
        return self.uuid

    def getLogged(self):
        return self.isLog
