from flask import current_app, g
from werkzeug.local import LocalProxy
from flask_pymongo import PyMongo

def get_db():
    db = getattr(g, "_database", None)
    if db is None:
        db = g._database = PyMongo(current_app).db
       
    return db

db = LocalProxy(get_db)

def get_sunspot():
    try:
        cursor = db.sunspot_light.find({}, { 'timestamp': 1, 'lux': 1, '_id': 0})
        data_list = []

        print(cursor)

        for doc in cursor:
            data_list.append(doc)
        
        return data_list
    except Exception as e:
        raise e 
    