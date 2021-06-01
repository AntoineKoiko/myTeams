class Team():
    def __init__(self, name, uuid = None, description=""):
        self.name = name
        self.uuid = uuid
        self.description = description

    def getName(self):
        return self.name

    def getUuid(self):
        return self.uuid

    def getDescription(self):
        return self.description
