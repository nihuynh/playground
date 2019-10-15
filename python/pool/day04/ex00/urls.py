from django.urls import path
from .views import Markdown

urlpatterns = [
    path('', Markdown, name='index.html')
]
