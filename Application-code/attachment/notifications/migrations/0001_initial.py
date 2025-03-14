# Generated by Django 5.0.6 on 2024-07-18 09:12

import django.db.models.deletion
from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        ('optibreed', '0004_delete_notification'),
    ]

    operations = [
        migrations.CreateModel(
            name='Notification',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('message', models.TextField()),
                ('timestamp', models.DateTimeField(auto_now_add=True)),
                ('status', models.CharField(choices=[('unread', 'Unread'), ('read', 'Read')], default='unread', max_length=10)),
                ('Room', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='optibreed.room')),
            ],
            options={
                'ordering': ['-timestamp'],
            },
        ),
    ]
