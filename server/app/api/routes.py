from flask import Blueprint, jsonify
from app.db import get_sunspot
from app.cache import cache 

api_bp = Blueprint('api', __name__)

@api_bp.route('/', methods=['GET'])
@cache.cached(timeout=600)
def index():
    try:
        data_list = get_sunspot()
        return jsonify(data_list)
    except ():
        print("error")