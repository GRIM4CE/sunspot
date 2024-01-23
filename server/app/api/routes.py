from flask import Blueprint, jsonify
from app.db import get_sunspot

api_bp = Blueprint('api', __name__)

@api_bp.route('/', methods=['GET'])
def index():
    try:
        data_list = get_sunspot()
        return jsonify(data_list)
    except ():
        print("error")