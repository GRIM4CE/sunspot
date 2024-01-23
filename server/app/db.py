from flask import current_app, g
from werkzeug.local import LocalProxy
from flask_pymongo import PyMongo

def get_db():
    db = getattr(g, "_database", None)
    if db is None:
        db = g._database = PyMongo(current_app).db
       
    return db

# Use LocalProxy to read the global db instance with just `db`
db = LocalProxy(get_db)

def get_sunspot():
    try:
        cursor = db.sunspot_records.find({}, { 'time': 1, 'visible': 1, 'uv': 1, 'ir': 1, '_id': 0})
        data_list = []
        for doc in cursor:
            data_list.append(doc)
        
        return data_list
    except Exception as e:
        raise e 
    